#include <iostream>
#include <stdio.h>
#include <stdlib.h>

inline int min(int a, int b) { return a > b? b: a; }

enum { UP = 1, LEFT };
typedef struct
{
  int x;
  int y;
  int needG;
  int needL;
  int vec;
} _info;

_info S[100000];
int TOP, MIN = 987654321;

int arrg[101][101];
int arrx[101][101], arry[101][101];
int T, M, N, L, G;
int main()
{
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    scanf("%d %d %d %d", &M, &N, &L, &G);
    for (int k = 0; k < M; k++) for (int l = 0; l < N-1; l++) {
      scanf("%d", &arrx[k][l]);
    }
    for (int k = 0; k < M-1; k++) for (int l = 0; l < N; l++) {
      scanf("%d", &arry[k][l]);
    }

    arrg[0][0] = 0;
    for (int k = 0; k < M; k++) {
      for (int l = 0; l < N; l++) {
        if (k > 0 && l > 0) {
          arrg[k][l] = min(arrg[k-1][l] + arry[k-1][l], arrg[k][l-1] + arrx[k][l-1]);
        } else {
          if (k == 0 && l > 0) {
            arrg[k][l] = arrg[k][l-1] + arrx[k][l-1];
          }
          if (k > 0 && l == 0) {
            arrg[k][l] = arrg[k-1][l] + arry[k-1][l];
          }
        }
      }
    }

    if (arrg[M-1][N-1] > G) {
      printf("%d\n", -1);
      continue;
    }

    MIN = 987654321;
    TOP = 0;
    _info e = { 0, 0, 0, 0, 0 };
    _info ele, nele;

    S[TOP++] = e;
    while (TOP > 0) {
      ele = S[--TOP];
      if (ele.x < 0 || ele.x >= N) continue;
      if (ele.y < 0 || ele.y >= M) continue;
      if (ele.needG > G) continue;
      if (ele.needL > MIN) continue;
      if (ele.x >= N - 1 && ele.y >= M - 1) {
        MIN = min(MIN, ele.needL);
      } else {
        if (ele.x >= 0 && ele.x < N) {
          nele.x = ele.x + 1;
          nele.y = ele.y;
          nele.needG = ele.needG + arrx[ele.y][ele.x];
          nele.needL = ele.needL + L;
          nele.vec = LEFT;
          if (ele.vec != 0 && nele.vec != ele.vec) nele.needL = nele.needL + 1;
          if (nele.needG <= G && nele.needL < MIN) S[TOP++] = nele;
        }

        if (ele.y >= 0 && ele.y < M) {
          nele.x = ele.x;
          nele.y = ele.y + 1;
          nele.needG = ele.needG + arry[ele.y][ele.x];
          nele.needL = ele.needL + L;
          nele.vec = UP;
          if (ele.vec != 0 && nele.vec != ele.vec) nele.needL = nele.needL + 1;
          if (nele.needG <= G && nele.needL < MIN) S[TOP++] = nele;
        }
      }
    }
    printf("%d\n", MIN);
  }
  return 0;
}

