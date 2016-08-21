#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct node {
	int v, e;
	bool operator<(const node& n) const { return e > n.e; }
};

int DP[1001];
vector<node> MAP[1001];
int main() {
	int N; cin >> N;
	int M; cin >> M;
	for (int i = 0; i < 1001; i++) DP[i] = 1e9;
	for (int i = 0; i < M; i++) {
		int va, vb, e; cin >> va >> vb >> e;
		MAP[va].push_back({ vb, e });
	}
	int S, E; cin >> S >> E;
	DP[S] = 0;

	priority_queue<node> Q;
	Q.push({ S, 0 });
	while (!Q.empty()) {
		node data = Q.top(); Q.pop();
		for (auto& v : MAP[data.v]) {
			if (DP[v.v] > DP[data.v] + v.e) {
				DP[v.v] = DP[data.v] + v.e;
				Q.push({ v.v, DP[v.v] });
			}
		}
	}

	cout << DP[E] << endl;
	return 0;
}
