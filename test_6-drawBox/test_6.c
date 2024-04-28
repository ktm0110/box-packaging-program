#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> // Mac에서는 이 헤더 파일을 포함합니다.

#define NUM_BOXES 2

float A, B, C;

// 왼쪽 상자의 가로, 세로, 높이, 좌표
float left_cube_width = 20;
float left_cube_height = 10;
float left_cube_depth = 30;
float left_cube_x = 0;
float left_cube_y = 0;
float left_cube_z = 0;

// 오른쪽 상자의 가로, 세로, 높이, 좌표
float right_cube_width = 0;
float right_cube_height = 0;
float right_cube_depth = 0;
float right_cube_x = 0;
float right_cube_y = 0;
float right_cube_z = 0;

int width = 160, height = 44; // 콘솔 창의 크기
float zBuffer[160 * 44];
char buffer[160 * 44];
int backgroundASCIICode = ' '; // 백그라운드 아스키코드를 공백으로 변경
int distanceFromCam = 100;
float K1 = 40;

float incrementSpeed = 0.6;

float x, y, z;
float ooz;
int xp, yp;
int idx;

void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch) {
    x = cubeX * sin(A) * sin(B) * cos(C) - cubeZ * cos(A) * sin(B) * cos(C) +
        cubeX * cos(A) * sin(C) + cubeZ * sin(A) * sin(C) + cubeY * cos(B) * cos(C);
    y = cubeX * cos(A) * cos(C) + cubeZ * sin(A) * cos(C) -
        cubeX * sin(A) * sin(B) * sin(C) + cubeZ * cos(A) * sin(B) * sin(C) -
        cubeY * cos(B) * sin(C);
    z = cubeZ * cos(A) * cos(B) - cubeX * sin(A) * cos(B) + cubeY * sin(B);

    ooz = 1 / (z + distanceFromCam);

    xp = (int)(width / 2 + K1 * ooz * x * 2);
    yp = (int)(height / 2 + K1 * ooz * y);

    idx = xp + yp * width;
    if (idx >= 0 && idx < width * height) {
        if (ooz > zBuffer[idx]) {
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }
}

int main() {
    printf("\x1b[2J");
    while (1) {
        memset(buffer, ' ', width * height); // 백그라운드 아스키코드를 공백으로 설정
        memset(zBuffer, 0, width * height * 4);

        // 왼쪽 상자 그리기
        for (float cubeX = -left_cube_width; cubeX < left_cube_width; cubeX += incrementSpeed) {
            for (float cubeY = -left_cube_height; cubeY < left_cube_height; cubeY += incrementSpeed) {
                calculateForSurface(cubeX + left_cube_x, cubeY + left_cube_y, -left_cube_depth + left_cube_z, '@');
                calculateForSurface(left_cube_width + left_cube_x, cubeY + left_cube_y, cubeX + left_cube_x, '$');
                calculateForSurface(-left_cube_width + left_cube_x, cubeY + left_cube_y, -cubeX + left_cube_x, '~');
                calculateForSurface(-cubeX + left_cube_x, cubeY + left_cube_y, left_cube_width + left_cube_x, '#');
                calculateForSurface(cubeX + left_cube_x, -left_cube_height + left_cube_y, -cubeY + left_cube_y, ';');
                calculateForSurface(cubeX + left_cube_x, left_cube_height + left_cube_y, cubeY + left_cube_y, '+');
            }
        }

        // 오른쪽 상자 그리기
        // 오른쪽 상자의 높이를 왼쪽 상자의 높이에 맞추기
        float right_cube_y_offset = left_cube_height - right_cube_height;
        for (float cubeX = -right_cube_width; cubeX < right_cube_width; cubeX += incrementSpeed) {
            for (float cubeY = -right_cube_height; cubeY < right_cube_height; cubeY += incrementSpeed) {
                calculateForSurface(cubeX + right_cube_x, cubeY + right_cube_y + right_cube_y_offset, -right_cube_depth + right_cube_z, '@');
                calculateForSurface(right_cube_width + right_cube_x, cubeY + right_cube_y + right_cube_y_offset, cubeX + right_cube_x, '$');
                calculateForSurface(-right_cube_width + right_cube_x, cubeY + right_cube_y + right_cube_y_offset, -cubeX + right_cube_x, '~');
                calculateForSurface(-cubeX + right_cube_x, cubeY + right_cube_y + right_cube_y_offset, right_cube_width + right_cube_x, '#');
                calculateForSurface(cubeX + right_cube_x, -right_cube_height + right_cube_y + right_cube_y_offset, -cubeY + right_cube_y + right_cube_y_offset, ';');
                calculateForSurface(cubeX + right_cube_x, right_cube_height + right_cube_y + right_cube_y_offset, cubeY + right_cube_y + right_cube_y_offset, '+');
            }
        }

        printf("\x1b[H");
        for (int k = 0; k < width * height; k++) {
            putchar(k % width ? buffer[k] : 10);
        }

        A += 0.05;
        B += 0.05;
        C += 0.01;
        usleep(10*16000);
    }
    return 0;
}
