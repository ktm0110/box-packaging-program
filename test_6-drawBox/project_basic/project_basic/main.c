#include <GL/glut.h>

// 직육면체의 위치 및 크기를 나타내는 구조체
typedef struct {
    float x, y, z; // 중심 좌표
    float width, height, depth; // 가로, 세로, 높이
} Cube;

Cube cube1 = { -1, 0, 0, 1, 1, 1 }; // 첫 번째 직육면체 초기화
Cube cube2 = { 0, 0, 0, 1, 1, 1 }; // 두 번째 직육면체 초기화

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // 배경색을 검은색으로 설정
    glEnable(GL_DEPTH_TEST); // 깊이 테스트 활성화
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0); // 카메라 위치 설정

    // 첫 번째 직육면체 그리기
    glPushMatrix(); // 변환 행렬 저장
    glTranslatef(cube1.x, cube1.y, cube1.z); // 이동 변환 적용
    glScalef(cube1.width, cube1.height, cube1.depth); // 크기 변환 적용
    glutWireCube(1.0); // 윤곽선만을 그리는 직육면체 그리기
    glPopMatrix(); // 저장한 변환 행렬 복원

    // 두 번째 직육면체 그리기
    glPushMatrix(); // 변환 행렬 저장
    glTranslatef(cube2.x, cube2.y, cube2.z); // 이동 변환 적용
    glScalef(cube2.width, cube2.height, cube2.depth); // 크기 변환 적용
    glutWireCube(1.0); // 윤곽선만을 그리는 직육면체 그리기
    glPopMatrix(); // 저장한 변환 행렬 복원

    glFlush(); // 그리기 명령 처리
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / (float)h, 1, 100); // 원근 투영 설정
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

