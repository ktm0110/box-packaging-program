#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int box1_size[3];
int box2_size[3];

void makeBox(int box1[], int box2[]);
int*** makeBigBox(int height, int depth, int width);
void placeBox(int*** big_box, int box1[], int box2[]);
void printBigBox(int*** big_box, int height, int depth, int width);
void freeBigBox_Array(int*** array, int height, int depth);
//-------------------
void init();
void drawCube(float x, float y, float z, float width, float height, float depth);
void display(int box1[], int box2[]);
void reshape(int w, int h);

int main(int argc, char** argv) {

    // 작은 상자 크기 생성
    makeBox(box1_size, box2_size);

    // 큰 상자의 크기 결정
    int max_height = box1_size[0] > box2_size[0] ? box1_size[0] : box2_size[0];
    int max_depth = box1_size[1] > box2_size[1] ? box1_size[1] : box2_size[1];
    int max_width = box1_size[2] + box2_size[2];

    // 큰 상자 생성
    int*** big_box = makeBigBox(max_height, max_depth, max_width);

    // 상자 배치
    placeBox(big_box, box1_size, box2_size);

    // 정면
    printBigBox(big_box, max_height, max_depth, max_width);

    // 메모리 해제
    freeBigBox_Array(big_box, max_height, max_depth);

    //---------------------------------------
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Cubes");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}


void makeBox(int box1[], int box2[]) {
    srand(time(NULL));
    // 순서대로 높이, 세로, 가로
    // height, depth, width
    for (int i = 0; i < 3; i++) {
        box1[i] = rand() % 10 + 1;
        box2[i] = rand() % 10 + 1;
    }
    printf("순서대로 가로, 세로, 높이\n");
    printf("박스1: %d, %d, %d\n박스2: %d, %d, %d\n\n", box1[2], box1[1], box1[0], box2[2], box2[1], box2[0]);
}

// 동적할당 및 0으로 초기화
int*** makeBigBox(int height, int depth, int width) {
    int*** array = (int***)malloc(height * sizeof(int**));
    if (array == NULL) {
        printf("메모리 할당 실패.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < height; i++) {
        array[i] = (int**)malloc(depth * sizeof(int*));
        if (array[i] == NULL) {
            printf("메모리 할당 실패.\n");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < depth; j++) {
            array[i][j] = (int*)malloc(width * sizeof(int));
            if (array[i][j] == NULL) {
                printf("메모리 할당 실패.\n");
                exit(EXIT_FAILURE);
            }

            for (int k = 0; k < width; k++) {
                array[i][j][k] = 0;
            }
        }
    }

    return array;
}

// 큰 상자 안에 작은 상자를 배치하는 함수
void placeBox(int*** big_box, int box1[], int box2[]) {

    /*
    // 확인용 배열 출력
    printf("빈 박스\n");
    for(int i=0; i< box2[0]; i++){
        for(int j=0; j<(box1[1]); j++){
            for(int k=0; k<box1[2]+box2[2]; k++){
                printf("%d ", big_box[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("==============\n\n");
    */
    // 큰 박스 1로 채우기
    // 큰 박스에 박스1 채우기
    for (int i = 0; i < box1[0]; i++) {
        for (int j = 0; j < box1[1]; j++) {
            for (int k = 0; k < box1[2]; k++) {
                big_box[i][j][k] = 1;
            }
        }
    }
    /*
    // 확인용 배열 출력
    printf("박스 1\n");
    for(int i=0; i< box2[0]; i++){
        for(int j=0; j<(box1[1]); j++){
            for(int k=0; k<box1[2]+box2[2]; k++){
                printf("%d ", big_box[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("==============\n\n");
    */
    // 큰 박스에 박스2 채우기
    for (int i = 0; i < box2[0]; i++) {
        for (int j = 0; j < box2[1]; j++) {
            for (int k = box1[2]; k < (box1[2] + box2[2]); k++) {
                big_box[i][j][k] = 1;
            }
        }
    }
    /*
    // 확인용 배열 출력
    printf("박스2\n");
    for(int i=0; i< box2[0]; i++){
        for(int j=0; j<(box1[1]); j++){
            for(int k=0; k<box1[2]+box2[2]; k++){
                printf("%d ", big_box[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("==============\n\n");
    */
}

// 배열 시각화
// 정면
void printBigBox(int*** big_box, int height, int depth, int width) {
    //printf("============\n");
    // 높이만 거꾸로 출력
    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < (width); j++) {
            printf("%d ", big_box[i][0][j]);
        }
        printf("\n");
    }
}

/*
void printBigBox(int ***array, int height, int depth, int width) {
    printf("3D 배열:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < width; k++) {
                printf("%d ", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
*/

// 메모리 해제
void freeBigBox_Array(int*** array, int height, int depth) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < depth; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

//------------------------삼각형 그리기---------------------------------------------
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // 검정 바탕
    glEnable(GL_DEPTH_TEST); //깊이 테스트
}

void drawCube(float x, float y, float z, float width, float height, float depth) {
    glPushMatrix(); // 변환 행렬 저장
    glTranslatef(x, y, z); // 이동 변환 적용
    glScalef(width, height, depth); // 크기 변환 적용
    glutWireCube(1.0); // 윤곽선만을 그리는 직육면체 그리기
    glPopMatrix(); // 저장한 변환 행렬 복원
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    if ((box1_size[0] + box2_size[0]) < 10 && (box1_size[1] + box2_size[1]) < 10 && (box1_size[2] + box2_size[2]) < 10) {
        gluLookAt(5, 5, 5, -2, 0, 0, 0, 1, 0); // 시점 설정
    }
    else
        gluLookAt(5, 15, 30, -2, 0, 0, 0, 1, 0); // 시점 설정

    // 첫 번째 직육면체
    float cube1_x = box1_size[2];    // 가로
    float cube1_y = box1_size[0];    // 높이
    float cube1_z = box1_size[1];    // 세로
    glColor3f(1.0, 0.0, 0.0); // 빨간색
    // (좌표, 크기)
    drawCube(-cube1_x / 2.0, cube1_y / 2.0, cube1_z / 2.0, cube1_x, cube1_y, cube1_z);

    // 두 번째 직육면체
    float cube2_x = box2_size[2];
    float cube2_y = box2_size[0];
    float cube2_z = box2_size[1];
    glColor3f(0.0, 1.0, 0.0);
    drawCube(cube2_x / 2.0, cube2_y / 2.0, cube2_z / 2.0, cube2_x, cube2_y, cube2_z);

    // 세 번째 직육면체
    float cube3_x = cube1_x + cube2_x;
    float cube3_y = cube1_y > cube2_y ? cube1_y : cube2_y;
    float cube3_z = cube1_z > cube2_z ? cube1_z : cube2_z;
    glColor3f(0.0, 0.0, 1.0);
    drawCube((-cube1_x / 2.0) + (cube2_x / 2.0), cube3_y / 2.0, cube3_z / 2.0, cube3_x, cube3_y, cube3_z);

    glFlush(); // 그리기 명령 처리
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / (float)h, 1, 100); // 원근 투영 설정
    glMatrixMode(GL_MODELVIEW);
}
