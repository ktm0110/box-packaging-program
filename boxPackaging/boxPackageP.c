#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void makeBox(int box1[], int box2[]);
int ***makeBigBox(int height, int depth, int width);
void placeBox(int ***big_box, int box1[], int box2[]);
void printBigBox(int ***big_box, int height, int depth, int width);
void freeBigBox_Array(int ***array, int height, int depth);



int main() {
    int box1_size[3];
    int box2_size[3];

    makeBox(box1_size, box2_size); // makeBox 함수 호출

    // 큰 상자의 치수 계산
    int max_height = (box1_size[0] > box2_size[0]) ? box1_size[0] : box2_size[0];
    int max_depth = (box1_size[1] > box2_size[1]) ? box1_size[1] : box2_size[1];
    int max_width = box1_size[2] + box2_size[2];

    // 큰 상자를 위한 메모리 동적 할당
    int ***big_box = makeBigBox(max_height, max_depth, max_width);

    // 상자 1을 큰 상자 안에 배치
    placeBox(big_box, box1_size, box2_size); // 시작 위치: (0, 0, 0)

    // 3D 배열 내용 시각화
    printBigBox(big_box, max_height, max_depth, max_width);

    // 동적으로 할당된 메모리 해제
    freeBigBox_Array(big_box, max_height, max_depth);

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
    printf("박스1: %d, %d, %d\n박스2: %d, %d, %d\n\n", box1[0], box1[1], box1[2], box2[0], box2[1], box2[2]);
}

// 동적할당 및 0으로 초기화
int ***makeBigBox(int height, int depth, int width) {
    int ***array = (int ***)malloc(height * sizeof(int **));
    if (array == NULL) {
        printf("메모리 할당 실패.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < height; i++) {
        array[i] = (int **)malloc(depth * sizeof(int *));
        if (array[i] == NULL) {
            printf("메모리 할당 실패.\n");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < depth; j++) {
            array[i][j] = (int *)malloc(width * sizeof(int));
            if (array[i][j] == NULL) {
                printf("메모리 할당 실패.\n");
                exit(EXIT_FAILURE);
            }

            for (int k = 0; k < width; k++) {
                array[i][j][k] = 0; // 모든 요소를 0으로 초기화
            }
        }
    }

    return array;
}

// 큰 상자 안에 작은 상자를 배치하는 함수
void placeBox(int ***big_box, int box1[], int box2[]) {
    
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
    for(int i=0; i<box1[0]; i++){
        for(int j=0; j<box1[1]; j++){
            for(int k=0; k<box1[2]; k++){
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
    for(int i=0; i<box2[0]; i++){
        for(int j=0; j<box2[1]; j++){
            for(int k=box1[2]; k<(box1[2] + box2[2]); k++){
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
void printBigBox(int ***big_box, int height, int depth, int width) {
    //printf("============\n");
    // 높이만 거꾸로 출력
    for(int i = height-1; i>=0; i--){
        for(int j=0; j<(width); j++){
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

// 동적으로 할당된 3D 배열 메모리를 해제하는 함수
void freeBigBox_Array(int ***array, int height, int depth) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < depth; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}