#include <iostream>
#include <algorithm>
using namespace std;
// 간선 정보
// http://cs.geneseo.edu/~baldwin/csci242/fall2011/1025fw.html
int main() {
  // define
  const int INF = 987654321;
  const int N = 4;
  // DP[i][j] = 노드i 에서 노드j까지 가기 위한 간선 비용
  // if (DP[i][j] == INF) 노드i에서 노드j에 갈수 없음
  int DP[N][N] = {
    { 0,   2,   1, INF },
    { 3,   0,   5,   1 },
    { 2, INF,   0,   3 },
    { 4, INF, INF,   0 }
  };

  // floyd warshall algorithm
  // 장점 : 각 정점을 기준으로의 모든 다른 정점까지의 최단거리를 구할 수 있다.
  // 단점 : O(N^3) 이므로 N의 크기가 1000 이상을 넘어가면 1초안에 해결이 불가능 하다.
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++)
        DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);

  // 수행 결과
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << DP[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
