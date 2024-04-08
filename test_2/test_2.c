//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int makeArray();

int main() {

	makeArray();

	return 0;
}


int makeArray(){
	int array[3][4][5];

	int ***ptrArray;

	ptrArray = (int ***)malloc(sizeof(int **) * 3);
	for (int i = 0; i < 3; i++) {
  		ptrArray[i] = (int **)malloc(sizeof(int *) * 4);
  		for (int j = 0; j < 4; j++) {
	    	ptrArray[i][j] = (int *)malloc(sizeof(int) * 5);
  		}
	}
	
}