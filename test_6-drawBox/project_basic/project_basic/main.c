#include <GL/glut.h>

// ������ü�� ��ġ �� ũ�⸦ ��Ÿ���� ����ü
typedef struct {
    float x, y, z; // �߽� ��ǥ
    float width, height, depth; // ����, ����, ����
} Cube;

Cube cube1 = { -1, 0, 0, 1, 1, 1 }; // ù ��° ������ü �ʱ�ȭ
Cube cube2 = { 0, 0, 0, 1, 1, 1 }; // �� ��° ������ü �ʱ�ȭ

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // ������ ���������� ����
    glEnable(GL_DEPTH_TEST); // ���� �׽�Ʈ Ȱ��ȭ
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0); // ī�޶� ��ġ ����

    // ù ��° ������ü �׸���
    glPushMatrix(); // ��ȯ ��� ����
    glTranslatef(cube1.x, cube1.y, cube1.z); // �̵� ��ȯ ����
    glScalef(cube1.width, cube1.height, cube1.depth); // ũ�� ��ȯ ����
    glutWireCube(1.0); // ���������� �׸��� ������ü �׸���
    glPopMatrix(); // ������ ��ȯ ��� ����

    // �� ��° ������ü �׸���
    glPushMatrix(); // ��ȯ ��� ����
    glTranslatef(cube2.x, cube2.y, cube2.z); // �̵� ��ȯ ����
    glScalef(cube2.width, cube2.height, cube2.depth); // ũ�� ��ȯ ����
    glutWireCube(1.0); // ���������� �׸��� ������ü �׸���
    glPopMatrix(); // ������ ��ȯ ��� ����

    glFlush(); // �׸��� ��� ó��
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / (float)h, 1, 100); // ���� ���� ����
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
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

