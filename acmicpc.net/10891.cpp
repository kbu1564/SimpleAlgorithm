#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int u, v, e;
	bool operator<(const node& n) const { return e < n.e; }
};
int P[100001], V[100001];
int  fi(int x) { return x == P[x]? x: P[x] = fi(P[x]); }
void un(int x, int y) { P[y] = x; }

int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i <= N; i++) P[i] = i;

	priority_queue<node> Q;
	for (int i = 0; i < M; i++) {
		int X, Y; scanf("%d %d", &X, &Y);
		Q.push({ X, Y, 1 });
	}

	int cycle = 0;
	while (!Q.empty()) {
		node data = Q.top(); Q.pop();
		if (fi(data.u) != fi(data.v)) {
			un(data.u, data.v);
		} else {
			if (V[data.u] == 0 || V[data.v] == 0) cycle++;
		}
		V[data.u] = 1; V[data.v] = 1;
	}

	cout << (cycle < 2? "Cactus": "Not cactus") << endl;
	return 0;
}

