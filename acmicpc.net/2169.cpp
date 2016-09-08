#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int MAP[1001][1001], DP[1001][1001];
int solve(int x, int y) {
	if (x < 0 || y < 0 || x >= M || y >= N) return 0;
	if (DP[y][x] > -1e9) return DP[y][x];

	if (DP[y][x] < solve(x-1, y) + MAP[y][x]) DP[y][x] = solve(x-1, y) + MAP[y][x];
	if (DP[y][x] < solve(x+1, y) + MAP[y][x]) DP[y][x] = solve(x+1, y) + MAP[y][x];
	if (DP[y][x] < solve(x, y-1) + MAP[y][x]) DP[y][x] = solve(x, y-1) + MAP[y][x];
	return DP[y][x];
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) DP[i][j] = -1e9;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &MAP[i][j]);

	printf("%d\n", solve(M-1, N-1));
	return 0;
}
