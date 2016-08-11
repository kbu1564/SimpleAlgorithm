#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int N, M, V;
int DFSV[1001], BFSV[1001];
int MAP[1001][1001];
void dfs(int root) {
	if (DFSV[root] == 1) return;
	DFSV[root] = 1;

	cout << root << " ";

	for (int i = 1; i <= N; i++)
		if (i != root && MAP[root][i] == 1 && DFSV[i] == 0)
			dfs(i);
}
int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int S, E; cin >> S >> E;
		MAP[S][E] = MAP[E][S] = 1;
	}

	dfs(V);
	cout << endl;

	queue<int> SQ;
	SQ.push(V);
	while (!SQ.empty()) {
		int node = SQ.front(); SQ.pop();

		if (BFSV[node] == 1) continue;
		BFSV[node] = 1;
		cout << node << " ";

		for (int i = 1; i <= N; i++) {
			if (node != i && MAP[node][i] == 1 && BFSV[i] == 0) {
				SQ.push(i);
			}
		}
	}
	cout << endl;
	return 0;
}
