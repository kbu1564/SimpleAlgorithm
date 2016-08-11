#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef struct { int x, y, c; } _p;
int n,m,F,R;
char V[101][101],M[101][101];
int ax[4] = { 0, 1, 0, -1 }, ay[4] = { -1, 0, 1, 0 };
_p Q[100000];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> M[i][j];

  V[0][0] = 1;
  Q[F++] = (_p){ 0, 0, 1 };
  while (R < F) {
    _p p = Q[R++];
    if (p.x == m-1 && p.y == n-1) {
      cout << p.c << endl;
    } else {
      for (int i = 0; i < 4; i++) {
        int nx = p.x + ax[i];
        int ny = p.y + ay[i];
        if (nx < 0 || nx >= m) continue;
        if (ny < 0 || ny >= n) continue;
        if (V[ny][nx] == 0 && M[ny][nx] == '1') {
          Q[F++] = (_p){ nx, ny, p.c+1 };
          V[ny][nx] = 1;
        }
      }
    }
  }
  return 0;
}

