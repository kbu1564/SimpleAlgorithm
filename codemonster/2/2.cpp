#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

struct item {
	int v;
	long long total;
	int count;
};

const int INF = 1e9;

int T, N, M, Q;
map<int, long long> MAP[10001];
map<int, long long> DP[10001];

long long nf(int s, int t) {
	if (DP[s][t] > 0) return DP[s][t];

	long long result = 0;
	queue<item> nfq;
	nfq.push({ s, INF, 0 });
	while (!nfq.empty()) {
		item data = nfq.front(); nfq.pop();

		if (DP[s][data.v] >= data.total) continue;
		DP[data.v][s] = DP[s][data.v] = data.total;

		for (auto& e : MAP[data.v]) {
			if (e.second == 0 || e.second == INF) continue;
			nfq.push({ e.first, min(data.total, e.second), data.count + 1 });
		}
	}
	return DP[s][t];
}

int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 10001; i++) MAP[i].clear(), DP[i].clear();

		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			int u, v, e;
			scanf("%d %d %d", &u, &v, &e);

			int minValue = MAP[u][v];
			if (minValue == 0) minValue = INF;

			MAP[u][v] = MAP[v][u] = min(minValue, e);
		}

		long long result = 0;
		scanf("%d", &Q);
		for (int i = 0; i < Q; i++) {
			int s, t;
			scanf("%d %d", &s, &t);
			long long flowValue = nf(s, t);
			if (flowValue < INF) {
				cout << s << " -> " << t << " = " << flowValue << endl;
				result += flowValue;
			}
		}

		printf("%lld\n", result);
	}
	return 0;
}

