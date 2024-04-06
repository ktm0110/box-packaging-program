#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int makeBox();

int main() {

	makeBox();

	return 0;
}

int makeBox() {
	srand(time(NULL));
	int box1[3];
	int box2[3];

	for (int i = 0; i < 3; i++) {
			box1[i] = rand() % 10 + 1;
	}

	printf("가로: %d, 세로: %d, 높이: %d", box1[0], box1[1], box1[2]);

	return box1;
}
