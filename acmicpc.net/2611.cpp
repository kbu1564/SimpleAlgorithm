#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int INF = 1e9;

struct edge {
	int v, e;
	bool operator<(const edge& eg) const { return e < eg.e; }
};

int N, M;
int DP[1001];
int PATH[1001];
int VIS[1001];
int MAP[1001][1001];
void dfs(int v, int e) {
	VIS[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (MAP[i][v] == 0) continue;
		if (DP[i] < e + MAP[i][v]) DP[i] = e + MAP[i][v];
		if (VIS[i] == 1) continue;
		dfs(i, e + MAP[i][v]);
		PATH[v] = i;
	}
	VIS[v] = 0;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, e; cin >> u >> v >> e;
		MAP[u][v] = max(e, MAP[u][v]);
	}

	dfs(1, 0);

	int result = 0;
	for (int i = 1; i <= N; i++) result = max(result, DP[i]);

	stack<int> bt;
	int curr = 1;
	while (curr != 0) {
		bt.push(curr);
		if (PATH[curr] == 0 && MAP[1][curr] > 0) bt.push(1);
		curr = PATH[curr];
	}

	cout << result << endl;
	while (!bt.empty()) {
		cout << bt.top() << " ";
		bt.pop();
	}
	cout << endl;
	return 0;
}

