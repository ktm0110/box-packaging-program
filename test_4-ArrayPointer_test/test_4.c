#include <stdio.h>
#include <stdlib.h>

// 모든 값을 0으로 설정된 3D 배열을 초기화하는 함수
int ***initialize3DArray(int width, int depth, int height) {
    int ***array = (int ***)malloc(width * sizeof(int **));
    if (array == NULL) {
        printf("메모리 할당 실패.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < width; i++) {
        array[i] = (int **)malloc(depth * sizeof(int *));
        if (array[i] == NULL) {
            printf("메모리 할당 실패.\n");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < depth; j++) {
            array[i][j] = (int *)malloc(height * sizeof(int));
            if (array[i][j] == NULL) {
                printf("메모리 할당 실패.\n");
                exit(EXIT_FAILURE);
            }

            for (int k = 0; k < height; k++) {
                array[i][j][k] = 0; // 모든 요소를 0으로 초기화
            }
        }
    }

    return array;
}

// 큰 상자 안에 작은 상자를 배치하는 함수
void placeBox(int ***big_box, int box_size[], int start_x, int start_y, int start_z) {
    int width = box_size[0];
    int depth = box_size[1];
    int height = box_size[2];

    for (int i = start_x; i < start_x + width; i++) {
        for (int j = start_y; j < start_y + depth; j++) {
            for (int k = start_z; k < start_z + height; k++) {
                big_box[i][j][k] = 1; // 점유된 공간을 1로 표시
            }
        }
    }
}

// 3D 배열의 내용을 시각화하는 함수
void visualize3DArray(int ***array, int width, int depth, int height) {
    printf("3D 배열:\n");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < height; k++) {
                printf("%d ", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// 동적으로 할당된 3D 배열 메모리를 해제하는 함수
void free3DArray(int ***array, int width, int depth) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < depth; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

int main() {
    // 두 상자의 크기 정의
    int box1_size[] = {2, 3, 4}; // 상자 1의 너비, 깊이, 높이
    int box2_size[] = {3, 2, 5}; // 상자 2의 너비, 깊이, 높이

    // 큰 상자의 치수 계산
    int max_width = box1_size[0] + box2_size[0];
    int max_depth = (box1_size[1] > box2_size[1]) ? box1_size[1] : box2_size[1];
    int max_height = (box1_size[2] > box2_size[2]) ? box1_size[2] : box2_size[2];

    // 큰 상자를 위한 메모리 동적 할당
    int ***big_box = initialize3DArray(max_width, max_depth, max_height);

    // 상자 1을 큰 상자 안에 배치
    placeBox(big_box, box1_size, 0, 0, 0); // 시작 위치: (0, 0, 0)

    // 상자 2를 큰 상자 안에 배치
    placeBox(big_box, box2_size, box1_size[0], 0, 0); // 시작 위치: (상자 1 너비, 0, 0)

    // 3D 배열 내용 시각화
    visualize3DArray(big_box, max_width, max_depth, max_height);

    // 동적으로 할당된 메모리 해제
    free3DArray(big_box, max_width, max_depth);

    return 0;
}
