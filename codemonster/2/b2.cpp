#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int INF = 1e9;
const int MAX = 10001;

struct edge {
	int u, v;
	long long e;
	bool operator<(const edge& eg) const { return e > eg.e; }
};

int T, N, M, Q;
int P[MAX];
vector<edge> MST[MAX];

int fi(int x) { return x == P[x]? x: P[x] = fi(P[x]); }
void un(int x, int y) { P[fi(y)] = fi(x); }

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		// 초기화
		for (int i = 0; i < MAX; i++) P[i] = i, MST[i].clear();

		priority_queue<edge> PQ;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			int u, v;
			long long e;
			scanf("%d %d %lld", &u, &v, &e);

			// 입력 데이터 일관성 유지
			int t = u;
			u = min(t, v);
			v = max(t, v);

			PQ.push({ u, v, -e });
		}

		// 최대 스패닝 트리
		while (!PQ.empty()) {
			edge data = PQ.top(); PQ.pop();
			if (fi(data.u) != fi(data.v)) {
				MST[data.u].push_back({ data.u, data.v, data.e });
				MST[data.v].push_back({ data.v, data.u, data.e });
				un(data.u, data.v);
			}
		}

		// 쿼리
		long long result = 0;
		scanf("%d", &Q);
		for (int i = 0; i < Q; i++) {
			int s, t;
			scanf("%d %d", &s, &t);
			if (s == t) continue;

			long long answer = 0;
			int visit[MAX] = { 0, };

			queue<edge> RQ;
			RQ.push({ 0, s, INF });
			while (!RQ.empty()) {
				edge data = RQ.front(); RQ.pop();
				if (visit[data.v] == 1) continue;
				visit[data.v] = 1;

				if (data.v == t) {
					answer = data.e;
					break;
				}

				for (auto& eg : MST[data.v]) {
					if (visit[eg.v] == 1) continue;
					RQ.push({ data.v, eg.v, min(data.e, -eg.e) });
				}
			}

			//cout << s << " -> " << t << " = " << -DP[s][t] << endl;
			if (answer < INF) result += answer;
		}

		printf("%lld\n", result);
	}
	return 0;
}

