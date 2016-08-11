#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int P[1001];
struct node {
	int va, vb, e;
	bool operator<(const node& n) const { return e > n.e; }
};
int  fi(int x) { return x == P[x]? x: P[x] = fi(P[x]); }
void un(int a, int b) { P[fi(a)] = fi(b); }
int main() {
	priority_queue<node> Q;
	int N; scanf("%d", &N);
	int M; scanf("%d", &M);
	for (int i = 0; i < 1001; i++) P[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		Q.push({ a, b, c });
	}

	int rst = 0;
	while (!Q.empty()) {
		node data = Q.top(); Q.pop();
		if (fi(data.va) != fi(data.vb)) {
			un(data.va, data.vb);
			rst += data.e;
		}
	}

	printf("%d\n", rst);
	return 0;
}
