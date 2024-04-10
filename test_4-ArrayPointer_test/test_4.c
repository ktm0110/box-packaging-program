#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int big_box_width;
    // 큰 상자를 담을 3차원 포인터 배열 할당
    int ***big_box;
    big_box = (int ***)malloc(max_width * sizeof(int **));
    for (int i = 0; i < max_width; i++) {
        big_box[i] = (int **)malloc(max_height * sizeof(int *));
        for (int j = 0; j < max_height; j++) {
            big_box[i][j] = (int *)malloc(max_depth * sizeof(int));
            // 할당한 메모리를 0으로 초기화
            for (int k = 0; k < max_depth; k++) {
                big_box[i][j][k] = 0;
            }
        }
    }

    // 상자 값 설정
    for (int i = 0; i < box1_width; i++) {
        for (int j = 0; j < box1_height; j++) {
            for (int k = 0; k < box1_depth; k++) {
                big_box[i][j][k] = 1;
            }
        }
    }
    for (int i = 0; i < box2_width; i++) {
        for (int j = 0; j < box2_height; j++) {
            for (int k = 0; k < box2_depth; k++) {
                big_box[i][j][k + box1_depth] = 1;
            }
        }
    }

    // 시각화
    printf("Visualizing big box:\n");
    for (int i = 0; i < max_width; i++) {
        for (int j = 0; j < max_height; j++) {
            for (int k = 0; k < max_depth; k++) {
                printf("%d ", big_box[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // 메모리 해제
    for (int i = 0; i < max_width; i++) {
        for (int j = 0; j < max_height; j++) {
            free(big_box[i][j]);
        }
        free(big_box[i]);
    }
    free(big_box);

    return 0;
}
