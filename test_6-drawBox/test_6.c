#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> // Mac에서는 이 헤더 파일을 포함합니다.

float A, B, C;

float cubeWidth1 = 20; // 가로
float cubeHeight1 = 10; // 세로
float cubeDepth1 = 5; // 높이

float cubeWidth2 = 10; // 가로
float cubeHeight2 = 15; // 세로
float cubeDepth2 = 8; // 높이

int width = 160, height = 44;
float zBuffer[160 * 44];
char buffer[160 * 44];
int backgroundASCIICode = '.';
int distanceFromCam = 100;
float horizontalOffset;
float K1 = 40;

float incrementSpeed = 0.6;

float x, y, z;
float ooz;
int xp, yp;
int idx;

float calculateX(int i, int j, int k, int cubeType) {
    if (cubeType == 1) {
        return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
            j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
    } else {
        return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
            j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C) + 25; // 25는 가로 길이의 차이를 반영한 값입니다.
    }
}

float calculateY(int i, int j, int k, int cubeType) {
    if (cubeType == 1) {
        return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
            j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
            i * cos(B) * sin(C);
    } else {
        return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
            j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
            i * cos(B) * sin(C);
    }
}

float calculateZ(int i, int j, int k, int cubeType) {
    if (cubeType == 1) {
        return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
    } else {
        return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B) + 3; // 3은 높이의 차이를 반영한 값입니다.
    }
}

void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch, int cubeType) {
    x = calculateX(cubeX, cubeY, cubeZ, cubeType);
    y = calculateY(cubeX, cubeY, cubeZ, cubeType);
    z = calculateZ(cubeX, cubeY, cubeZ, cubeType) + distanceFromCam;

    ooz = 1 / z;

    xp = (int)(width / 2 + horizontalOffset + K1 * ooz * x * 2);
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
        memset(buffer, backgroundASCIICode, width * height);
        memset(zBuffer, 0, width * height * 4);
        cubeWidth1 = 20; // 첫 번째 사각형의 가로
        cubeHeight1 = 10; // 첫 번째 사각형의 세로
        cubeDepth1 = 5; // 첫 번째 사각형의 높이
        cubeWidth2 = 10; // 두 번째 사각형의 가로
        cubeHeight2 = 15; // 두 번째 사각형의 세로
        cubeDepth2 = 8; // 두 번째 사각형의 높이
        horizontalOffset = -2 * cubeWidth1;
        // 첫 번째 사각형
        for (float cubeX = -cubeWidth1; cubeX < cubeWidth1; cubeX += incrementSpeed) {
            for (float cubeY = -cubeHeight1; cubeY < cubeHeight1; cubeY += incrementSpeed) {
                calculateForSurface(cubeX, cubeY, -cubeDepth1, '@', 1);
                calculateForSurface(cubeWidth1, cubeY, cubeX, '$', 1);
                calculateForSurface(-cubeWidth1, cubeY, -cubeX, '~', 1);
                calculateForSurface(-cubeX, cubeY, cubeWidth1, '#', 1);
                calculateForSurface(cubeX, -cubeHeight1, -cubeY, ';', 1);
                calculateForSurface(cubeX, cubeHeight1, cubeY, '+', 1);
            }
        }
        // 두 번째 사각형
        horizontalOffset = 2 * cubeWidth1; // 가로 길이의 차이를 반영
        for (float cubeX = -cubeWidth2; cubeX < cubeWidth2; cubeX += incrementSpeed) {
            for (float cubeY = -cubeHeight2; cubeY < cubeHeight2; cubeY += incrementSpeed) {
                calculateForSurface(cubeX, cubeY, -cubeDepth2, '@', 2);
                calculateForSurface(cubeWidth2, cubeY, cubeX, '$', 2);
                calculateForSurface(-cubeWidth2, cubeY, -cubeX, '~', 2);
                calculateForSurface(-cubeX, cubeY, cubeWidth2, '#', 2);
                calculateForSurface(cubeX, -cubeHeight2, -cubeY, ';', 2);
                calculateForSurface(cubeX, cubeHeight2, cubeY, '+', 2);
            }
        }
        printf("\x1b[H");
        for (int k = 0; k < width * height; k++) {
            putchar(k % width ? buffer[k] : 10);
        }

        A += 0.05;
        B += 0.05;
        C += 0.01;
        usleep(8000 * 2);
    }
    return 0;
}
