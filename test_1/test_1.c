#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void makeBox();
//int makeArray(arr1, arr2);

int main() {

	makeBox();

	return 0;
}

void makeBox() {
	srand(time(NULL));
	int box1[3];
	int box2[3];

	for (int i = 0; i < 3; i++) {
			box1[i] = rand() % 10 + 1;
	}

	printf("����: %d, ����: %d, ����: %d", box1[0], box1[1], box1[2]);

	//return box1;
	//int makeArray(box1, box2);
}

/*int makeArray(box1, box2){
	int array[3][4][5];

	int ***ptrArray;

	ptrArray = (int ***)malloc(sizeof(int **) * 3);
	for (int i = 0; i < 3; i++) {
  		ptrArray[i] = (int **)malloc(sizeof(int *) * 4);
  		for (int j = 0; j < 4; j++) {
	    	ptrArray[i][j] = (int *)malloc(sizeof(int) * 5);
  		}
	}
	
}*/