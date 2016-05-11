#include <queue>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
const int SIZE = 20001;
const int N = 5; // 정점 개수
const int S = 1; // 시작 노드 번호
int D[SIZE];

// 최소 우선순위 큐 지정을 위한 구조체 정의
struct node {
  int v, e;
  bool operator<(const node& n) const { return e > n.e; }
};

int main() {
  // 기본 모든 경로를 무한대로 셋팅
  for (int i = 0; i < SIZE; i++) D[i] = INF;

  // 간선 정보 셋팅
  vector<node> M[SIZE];
  M[5].push_back({ 1, 1 });
  M[1].push_back({ 2, 2 });
  M[1].push_back({ 3, 3 });
  M[2].push_back({ 3, 4 });
  M[2].push_back({ 4, 5 });
  M[3].push_back({ 4, 6 });

  // 시작점 셋팅
  priority_queue<node> Q;
  Q.push({ S, 0 });
  D[S] = 0;
  while (!Q.empty()) {
    node V = Q.top(); Q.pop();
    if (V.e > D[V.v]) continue;
    for (auto x : M[V.v]) {
      if (D[x.v] > D[V.v] + x.e) {
        D[x.v] = D[V.v] + x.e;
        Q.push({ x.v, D[x.v] });
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    if (D[i] == INF) cout << "INF" << endl;
    else cout << D[i] << endl;
	}

  return 0;
}
