#include <iostream>
using namespace std;
int t,n,m,k,x,y;
int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
typedef struct { int x, y; } p;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    int A[51][51] = { 0, };
    int V[51][51] = { 0, };
    cin >> m >> n >> k;
    for (int j = 0; j < k; j++) {
      cin >> x >> y;
      A[y][x] = 1;
    }

    int a = 0;
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < m; l++) {
        if (V[j][l] == 1 || A[j][l] == 0) continue;
        p Q[25001];
        int c = 0, f = 0, r = 0;
        Q[f++] = (p){ l, j };
        while (r < f) {
          p pos = Q[r++];
          if (V[pos.y][pos.x] == 1) continue;
          V[pos.y][pos.x] = 1;
          c++;
          for (int o = 0; o < 4; o++) {
            int dx = pos.x + AX[o];
            int dy = pos.y + AY[o];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
              if (A[dy][dx] == 1 && V[dy][dx] == 0) {
                Q[f++] = (p){ dx, dy };
              }
            }
          }
        }
        if (c > 0) a++;
      }
    }
    cout << a << endl;
  }
  return 0;
}

