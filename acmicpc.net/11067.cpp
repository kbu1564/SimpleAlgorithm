#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct { int x, y; } _pos;
int compareXY(const void* n1, const void* n2) {
  int dx = ((*(_pos*)n1).x - (*(_pos*)n2).x);
  return dx? dx: ((*(_pos*)n1).y - (*(_pos*)n2).y);
}
int compareY1(const void* n1, const void* n2) {
  return (*(_pos*)n1).y - (*(_pos*)n2).y;
}
int compareY2(const void* n1, const void* n2) {
  return (*(_pos*)n2).y - (*(_pos*)n1).y;
}
int t,n,m;
_pos P[100000];
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
      scanf("%d %d", &(P[j].x), &(P[j].y));

    qsort(P, n, sizeof(_pos), compareXY);

    int start = 0;
    _pos chk = (_pos){ 0, 0 };
    for (int j = 0; j < n; j++) {
      if (j+1 == n || P[j].x != chk.x) {
        int mi = chk.y;
        int mx = chk.y;
        for (int k = start; k < n; k++) {
          if (P[k].x != chk.x) break;
          if (mi > P[k].y) mi = P[k].y;
          if (mx < P[k].y) mx = P[k].y;
        }

        int count = j-start;
        if (j+1 == n) count = n-start;

        if (mx == chk.y) {
          qsort(P+start, count, sizeof(_pos), compareY2);
          chk.y = mi;
        } else if (mi == chk.y) {
          qsort(P+start, count, sizeof(_pos), compareY1);
          chk.y = mx;
        }
        start = j;
      }
      chk.x = P[j].x;
    }

    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
      int mm = 0;
      scanf("%d", &mm);
      printf("%d %d\n", P[mm-1].x, P[mm-1].y);
    }
  }
  return 0;
}
