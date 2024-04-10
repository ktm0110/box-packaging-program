#include <stdio.h>

void choose_WDH(int b1[], int b2[]);

int main(){
    int box1[] = {3, 6, 9};
    int box2[] = {7, 9, 2};
/*
    int width_1 = 3, width_2 = 7;
    int depth_1 = 6, depth_2 = 9;
    int height_1 = 9, height_2 = 2;
*/
    choose_WDH(box1, box2);

    return 0;
}

void choose_WDH(int box1[], int box2[]){
    int big_box[3] = {0};

    big_box[0] = box1[0] + box2[0];

    for(int i=1; i<=2; i++){
        if(box1[i] >= box2[i])
            big_box[i] = box1[i];
        else
            big_box[i] = box2[i];
    }    
    //printf("%d %d %d", big_box[0], big_box[1], big_box[2]);

}
