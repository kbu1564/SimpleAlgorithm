#include <iostream>
using namespace std;
const int INF = 1e9;
const int SIZE = 100000;
const int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
struct item { int x, y, c; };
int main() {
  const int N = 6; // rows
  const int M = 4; // cols
  /*
  0 : 길
  1 : 벽
  (0, 0) : 출발점
  (N, M) : 도착점
  */
  int MAP[N][M] = {
    { 0, 0, 0, 0 },
    { 1, 1, 1, 0 },
    { 1, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 1, 1, 1 },
    { 0, 0, 0, 0 }
  };
  int VIS[N][M]; // 방문 배열
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) VIS[i][j] = INF;

  // BFS의 탐색방식은 수면 파동과 같이 원형으로 탐색되어진다고 생각하면 이해가 조금 더 쉽다.
  item Q[SIZE];
  int f = 0, r = 0;

  Q[r++] = { 0, 0, 1 };
  r %= SIZE;
  while (f != r) {
    item data = Q[f++];
    f %= SIZE;
    VIS[data.y][data.x] = data.c;
    for (int i = 0; i < 4; i++) {
      item next = { data.x + AX[i], data.y + AY[i], data.c + 1 };
      if (next.x < 0 || next.y < 0 || next.x >= M || next.y >= N) continue;
      if (next.c > VIS[next.y][next.x]) continue;
      if (MAP[next.y][next.x] == 1) continue;
      Q[r++] = next;
      r %= SIZE;
    }
  }
  cout << VIS[M][N] << endl;
  return 0;
}

