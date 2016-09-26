#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, w;
};

int T;
int N, D;
vector<edge> MAP[40001];
int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 40001; i++) MAP[i].clear();

		scanf("%d %d", &N, &D);
		for (int i = 0; i < N-1; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			MAP[u].push_back({ u, v, w });
			MAP[v].push_back({ v, u, w });
		}

		for (int i = 1; i <= N; i++) {
			if (MAP[i].size() == 1) {
				printf("Root : %d\n", i);
			}
		}
	}
	return 0;
}
