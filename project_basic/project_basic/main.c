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

    // ���� ���� ũ�� ����
    makeBox(box1_size, box2_size);

    // ū ������ ũ�� ����
    int max_height = box1_size[0] > box2_size[0] ? box1_size[0] : box2_size[0];
    int max_depth = box1_size[1] > box2_size[1] ? box1_size[1] : box2_size[1];
    int max_width = box1_size[2] + box2_size[2];

    // ū ���� ����
    int*** big_box = makeBigBox(max_height, max_depth, max_width);

    // ���� ��ġ
    placeBox(big_box, box1_size, box2_size);

    // ����
    printBigBox(big_box, max_height, max_depth, max_width);

    // �޸� ����
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
    // ������� ����, ����, ����
    // height, depth, width
    for (int i = 0; i < 3; i++) {
        box1[i] = rand() % 10 + 1;
        box2[i] = rand() % 10 + 1;
    }
    printf("������� ����, ����, ����\n");
    printf("�ڽ�1: %d, %d, %d\n�ڽ�2: %d, %d, %d\n\n", box1[2], box1[1], box1[0], box2[2], box2[1], box2[0]);
}

// �����Ҵ� �� 0���� �ʱ�ȭ
int*** makeBigBox(int height, int depth, int width) {
    int*** array = (int***)malloc(height * sizeof(int**));
    if (array == NULL) {
        printf("�޸� �Ҵ� ����.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < height; i++) {
        array[i] = (int**)malloc(depth * sizeof(int*));
        if (array[i] == NULL) {
            printf("�޸� �Ҵ� ����.\n");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < depth; j++) {
            array[i][j] = (int*)malloc(width * sizeof(int));
            if (array[i][j] == NULL) {
                printf("�޸� �Ҵ� ����.\n");
                exit(EXIT_FAILURE);
            }

            for (int k = 0; k < width; k++) {
                array[i][j][k] = 0;
            }
        }
    }

    return array;
}

// ū ���� �ȿ� ���� ���ڸ� ��ġ�ϴ� �Լ�
void placeBox(int*** big_box, int box1[], int box2[]) {

    /*
    // Ȯ�ο� �迭 ���
    printf("�� �ڽ�\n");
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
    // ū �ڽ� 1�� ä���
    // ū �ڽ��� �ڽ�1 ä���
    for (int i = 0; i < box1[0]; i++) {
        for (int j = 0; j < box1[1]; j++) {
            for (int k = 0; k < box1[2]; k++) {
                big_box[i][j][k] = 1;
            }
        }
    }
    /*
    // Ȯ�ο� �迭 ���
    printf("�ڽ� 1\n");
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
    // ū �ڽ��� �ڽ�2 ä���
    for (int i = 0; i < box2[0]; i++) {
        for (int j = 0; j < box2[1]; j++) {
            for (int k = box1[2]; k < (box1[2] + box2[2]); k++) {
                big_box[i][j][k] = 1;
            }
        }
    }
    /*
    // Ȯ�ο� �迭 ���
    printf("�ڽ�2\n");
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

// �迭 �ð�ȭ
// ����
void printBigBox(int*** big_box, int height, int depth, int width) {
    //printf("============\n");
    // ���̸� �Ųٷ� ���
    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < (width); j++) {
            printf("%d ", big_box[i][0][j]);
        }
        printf("\n");
    }
}

/*
void printBigBox(int ***array, int height, int depth, int width) {
    printf("3D �迭:\n");
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

// �޸� ����
void freeBigBox_Array(int*** array, int height, int depth) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < depth; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

//------------------------�ﰢ�� �׸���---------------------------------------------
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // ���� ����
    glEnable(GL_DEPTH_TEST); //���� �׽�Ʈ
}

void drawCube(float x, float y, float z, float width, float height, float depth) {
    glPushMatrix(); // ��ȯ ��� ����
    glTranslatef(x, y, z); // �̵� ��ȯ ����
    glScalef(width, height, depth); // ũ�� ��ȯ ����
    glutWireCube(1.0); // ���������� �׸��� ������ü �׸���
    glPopMatrix(); // ������ ��ȯ ��� ����
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    if ((box1_size[0] + box2_size[0]) < 10 && (box1_size[1] + box2_size[1]) < 10 && (box1_size[2] + box2_size[2]) < 10) {
        gluLookAt(5, 5, 5, -2, 0, 0, 0, 1, 0); // ���� ����
    }
    else
        gluLookAt(5, 15, 30, -2, 0, 0, 0, 1, 0); // ���� ����

    // ù ��° ������ü
    float cube1_x = box1_size[2];    // ����
    float cube1_y = box1_size[0];    // ����
    float cube1_z = box1_size[1];    // ����
    glColor3f(1.0, 0.0, 0.0); // ������
    // (��ǥ, ũ��)
    drawCube(-cube1_x / 2.0, cube1_y / 2.0, cube1_z / 2.0, cube1_x, cube1_y, cube1_z);

    // �� ��° ������ü
    float cube2_x = box2_size[2];
    float cube2_y = box2_size[0];
    float cube2_z = box2_size[1];
    glColor3f(0.0, 1.0, 0.0);
    drawCube(cube2_x / 2.0, cube2_y / 2.0, cube2_z / 2.0, cube2_x, cube2_y, cube2_z);

    // �� ��° ������ü
    float cube3_x = cube1_x + cube2_x;
    float cube3_y = cube1_y > cube2_y ? cube1_y : cube2_y;
    float cube3_z = cube1_z > cube2_z ? cube1_z : cube2_z;
    glColor3f(0.0, 0.0, 1.0);
    drawCube((-cube1_x / 2.0) + (cube2_x / 2.0), cube3_y / 2.0, cube3_z / 2.0, cube3_x, cube3_y, cube3_z);

    glFlush(); // �׸��� ��� ó��
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / (float)h, 1, 100); // ���� ���� ����
    glMatrixMode(GL_MODELVIEW);
}
