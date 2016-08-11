#include <iostream>
#include <cmath>
using namespace std;

const int DEBUG = 0;

typedef struct { float x, y; } _pos;
_pos v[4];
int c,t,tx,ty,ax1,ax2,ay1,ay2,lx1,lx2,ly1,ly2;
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d %d %d", &ax1, &ay1, &ax2, &ay2);
    scanf("%d %d %d %d", &lx1, &ly1, &lx2, &ly2);

    tx = lx1;
    ty = ly1;
    lx1 = min(tx, lx2);
    lx2 = max(tx, lx2);
    ly1 = min(ty, ly2);
    ly2 = max(ty, ly2);

    int dx = lx2 - lx1;
    int dy = ly2 - ly1;
    int dxb = dx * ly1 - dy * lx1;

    if (DEBUG == 1) {
      // 직선 방정식
      printf("y = (%d/%d)x + %d/%d\n", dy, dx, dxb, dx);
      printf("%d<=x<=%d 라면 %d<=y<=%d 이다\n", lx1, lx2, ly1, ly2);

      // 사각형 방정식
      printf("x = %d, x = %d\n", ax1, ax2);
      printf("%d<=y<=%d\n", ay1, ay2);
      printf("y = %d, y = %d\n", ay1, ay2);
      printf("%d<=x<=%d\n", ax1, ax2);
    }

    // (y - b)/a = x
    // x = ax1, ax2 일때의 y값의 범위가 ay1 ~ ay2 범위인가?
    float x1 = (dx*ay1 - dxb) / (float)dy;
    float x2 = (dx*ay2 - dxb) / (float)dy;
    // y 동일
    float y1 = (dy*ax1 + dxb)/(float)dx;
    float y2 = (dy*ax2 + dxb)/(float)dx;

    v[0] = (_pos){ (float)ax1, y1 };
    v[1] = (_pos){ (float)ax2, y2 };
    v[2] = (_pos){ x1, (float)ay1 };
    v[3] = (_pos){ x2, (float)ay2 };
    if (DEBUG == 1) {
      for (int j = 0; j < 4; j++) printf("(%.2f, %.2f)\n", v[j].x, v[j].y);
    }
    
    c = 0;
    int minax = min(ax1, ax2);
    int maxax = max(ax1, ax2);
    int minay = min(ay1, ay2);
    int maxay = max(ay1, ay2);
    for (int j = 0; j < 4; j++) {
      if ((v[j].x == ax1 || v[j].x == ax2) && (v[j].y >= minay && v[j].y <= maxay))
          c++;
      else if ((v[j].y == ay1 || v[j].y == ay2) && (v[j].x >= minax && v[j].x <= maxax))
          c++;
    }
    // y = ay1 과 (lx1, ly1), (lx2, ly2) 의 방정식의 연립 해를 비교
    // 해가 무수히 많다
    //if (ly1 == ly2 && (ly1 == ay1 || ly1 == ay2)) c = 4;
    //if (lx1 == lx2 && (lx1 == ax1 || lx1 == ax2)) c = 4;
    // 해가 유한개
    //if (ly1 == ly2 && lx1 == lx2) {
    //}
    printf("%d\n", c);
 }
  return 0;
}

