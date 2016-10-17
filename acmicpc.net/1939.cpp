#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct edge {
	int u, v, e;
	bool operator<(const edge& eg) const { return e > eg.e; }
};

const int INF = 1e9;

vector<edge> MAP[100001];
vector<edge> MST[100001];
int VIS[100001];
int P[100001];
int  fi(int x) { return x == P[x]? x: P[x] = fi(P[x]); }
void un(int a, int b) { P[fi(b)] = fi(a); }

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < 100001; i++) P[i] = i;

	priority_queue<edge> PQ;
	for (int i = 0; i < M; i++) {
		int u, v, e;
		scanf("%d %d %d", &u, &v, &e);
		PQ.push({ min(u, v), max(u, v), -e });
	}

	int from = 0, to = 0;
	scanf("%d %d", &from, &to);

	while (!PQ.empty()) {
		edge data = PQ.top(); PQ.pop();
		if (fi(data.u) != fi(data.v)) {
			MST[data.u].push_back({ data.u, data.v, data.e });
			MST[data.v].push_back({ data.v, data.u, data.e });
			un(data.u, data.v);
		}
	}

	int result = 0;
	queue<edge> Q;
	Q.push({ 0, from, -INF });
	while (!Q.empty()) {
		edge data = Q.front(); Q.pop();
		if (VIS[data.v] == 1) continue;
		VIS[data.v] = 1;

		if (data.v == to) {
			result = max(result, -data.e);
			break;
		}

		for (auto& eg : MST[data.v]) {
			Q.push({ eg.u, eg.v, max(eg.e, data.e) });
		}
	}

	printf("%d\n", result);
	return 0;
}
