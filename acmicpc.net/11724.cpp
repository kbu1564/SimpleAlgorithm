#include <iostream>
using namespace std;
int P[1001];
int C[1001];
pair<int, int> UV[500001];
int Find(int x) { return x == P[x]? x: P[x] = Find(P[x]); }
void Union(int a, int b) { P[Find(b)] = Find(a); }
int main() {
	for (int i = 0; i < 1001; i++) P[i] = i;

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		UV[i] = pair<int, int>(min(u, v), max(u, v));
		P[UV[i].second] = UV[i].first;
	}

	for (int i = 0; i < M; i++) {
		Union(UV[i].first, UV[i].second);
	}

	for (int i = 1; i <= N; i++) C[P[i]]++;

	int result = 0;
	for (int i = 1; i <= N; i++) if (C[i] > 0) result++;
	cout << result << endl;
	return 0;
}

