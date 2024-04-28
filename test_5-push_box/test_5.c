#include <stdio.h>


int main(){
    //--------높이,세로,가로
    int box1[]={3,2,6};
    int box2[]={4,1,4};

    //3차원 배열 -면,행,열
    //-순서대로--height,depth,width
    int bigbox[box2[0]][box1[1]][box1[2]+box2[2]];

    // 큰 박스 0으로 초기화
    for(int i=0; i< box2[0]; i++){
        for(int j=0; j<(box1[1]); j++){
            for(int k=0; k<box1[2]+box2[2]; k++){
                bigbox[i][j][k] = 0;
            }
        }
    }
    for(int i=0; i< box2[0]; i++){
        for(int j=0; j<(box1[1]); j++){
            for(int k=0; k<box1[2]+box2[1]; k++){
                printf("%d ", bigbox[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("==============\n\n");

    // 큰 박스 1로 채우기

    // 박스 1 채우기
    for(int i=0; i<box1[0]; i++){
        for(int j=0; j<box1[1]; j++){
            for(int k=0; k<box1[2]; k++){
                bigbox[i][j][k] = 1;
            }
        }
    }
    // 확인용 배열 출력
    for(int i=0; i< box2[0]; i++){
        for(int j=0; j<(box1[1]); j++){
            for(int k=0; k<box1[2]+box2[2]; k++){
                printf("%d ", bigbox[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("==============\n\n");

    // 큰 박스 0으로 초기화
    for(int i=0; i< box2[0]; i++){
        for(int j=0; j<(box1[1]); j++){
            for(int k=0; k<box1[2]+box2[2]; k++){
                bigbox[i][j][k] = 0;
            }
        }
    }
    // 박스 2 채우기
    for(int i=0; i<box2[0]; i++){
        for(int j=0; j<box2[1]; j++){
            for(int k=box1[2]; k<(box1[2] + box2[2]); k++){
                bigbox[i][j][k] = 1;
            }
        }
    }

    // 확인용 배열 출력
    for(int i=0; i< box2[0]; i++){
        for(int j=0; j<(box1[1]); j++){
            for(int k=0; k<box1[2]+box2[2]; k++){
                printf("%d ", bigbox[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}