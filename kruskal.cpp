#include <iostream>
#include <queue>
using namespace std;
//             A    B    C    D    E    F    G
int  P[7] = {  0,   1,   2,   3,   4,   5,   6 };
char N[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
// 그래프의 사이클 생성 여부 체크 함수
int  fi(int x) { return x == P[x]? x: P[x] = fi(P[x]); }
// 합집합 체크 함수
void un(int x, int y) { P[fi(y)] = fi(x); }
struct node {
  int va, vb, e;
  bool operator<(const node& n) const { return e > n.e; }
};
int main() {
  priority_queue<node> Q;

  // 간선 정보 삽입
  // va -> vb 비용 : e
  Q.push({ 0, 1, 7 });
  Q.push({ 0, 3, 5 });
  Q.push({ 1, 2, 8 });
  Q.push({ 1, 3, 9 });
  Q.push({ 1, 4, 7 });
  Q.push({ 2, 4, 5 });
  Q.push({ 3, 4, 15 });
  Q.push({ 3, 5, 6 });
  Q.push({ 4, 5, 8 });
  Q.push({ 5, 6, 11 });
  Q.push({ 4, 6, 9 });

  // 크러스컬 알고리즘
  while (!Q.empty()) {
    node data = Q.top(); Q.pop();
    if (fi(data.va) != fi(data.vb)) {
      cout << N[data.va] << " -> " << N[data.vb] << " = " << data.e << endl;
      un(data.va, data.vb);
    }
  }
  return 0;
}
