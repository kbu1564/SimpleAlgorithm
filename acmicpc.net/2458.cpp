#include <iostream>
using namespace std;
int INF = 1e9;
int ST[501][501];
int BT[501][501];
int main() {
	int N; cin >> N;
	int M; cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		BT[a][b] = 1;
		ST[b][a] = 1;
	}

