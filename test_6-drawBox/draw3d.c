#include <stdio.h>

int main() {
  // 상자 크기 설정 (예시: 5x5x5)
  int width = 5;
  int height = 5;
  int depth = 5;

  // 투영 평면 설정 (예시: z = 2)
  int projectionPlane = 2;

  // 상자 벽 표시
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // 벽 (x, y, projectionPlane) 좌표 체크
      if (projectionPlane == 0 || projectionPlane == depth - 1) {
        if (x == 0 || x == width - 1) {
          printf("|"); // 앞면/뒷면 벽 표시
        } else {
          printf("-"); // 윗면/아랫면 벽 표시
        }
      } else if (projectionPlane == x || projectionPlane == width - 1 - x) {
        if (y == 0 || y == height - 1) {
          if (x == 0 || x == width - 1) {
            printf("+"); // 모서리 벽 표시
          } else {
            printf("\\"); // 앞면/뒷면 모서리 벽 표시
          }
        } else {
          printf("/"); // 윗면/아랫면 모서리 벽 표시
        }
      } else {
        printf(" "); // 공간 표시
      }
    }
    printf("\n"); // 줄 바꿈
  }

  return 0;
}
