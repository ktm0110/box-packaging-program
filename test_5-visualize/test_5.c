#include <stdio.h>


int main(){
    //--------깊이,가로,높이
    int box1[]={3,2,6};
    int box2[]={4,1,4};

    //3차원 배열 -면,행,열
    //-순서대로--depth,width,height
    int bigbox[box2[0]][box1[1]+box2[1]][box1[2]];

    // 큰 박스 0으로 초기화
    for(int i=0; i< box2[0]; i++){
        for(int j=0; j<(box1[1]+box2[1]); j++){
            for(int k=0; k<box1[2]; k++){
                bigbox[i][j][k] = 0;
            }
        }
    }
    for(int i=0; i< box2[0]; i++){
        for(int j=0; j<(box1[1]+box2[1]); j++){
            for(int k=0; k<box1[2]; k++){
                printf("%d ", bigbox[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    

    return 0;
}