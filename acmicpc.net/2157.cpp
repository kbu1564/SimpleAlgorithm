#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K;
int DP[301][301];
int MAP[301][301];
int solve(int n, int c) {
	if (c > M) return 0;

	int result = 0;
	for (int i = n + 1; i <= N; i++) {
		if (MAP[n][i] <= 0) continue;
		if (DP[i][c+1] < solve(i, c+1) + MAP[n][i]) {
			DP[i][c+1] = solve(i, c+1) + MAP[n][i];
			result = max(result, DP[i][c+1]);
		}
	}
	return result;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < 301; i++) for (int j = 0; j < 301; j++) DP[i][j] = -1;
	for (int i = 0; i < K; i++) {
		int va, vb, e;
		scanf("%d %d %d", &va, &vb, &e);
		MAP[va][vb] = max(MAP[va][vb], e);
	}

	cout << solve(1, 0) << endl;
	return 0;
}

