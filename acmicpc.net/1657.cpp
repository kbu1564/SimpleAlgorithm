#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N, M;
int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
int VIS[15][15];
int SCORE[6][6] = {
	{ 10, 8, 7, 5, 0, 1 },
	{  8, 6, 4, 3, 0, 1 },
	{  7, 4, 3, 2, 0, 1 },
	{  5, 3, 2, 2, 0, 1 },
	{  0, 0, 0, 0, 0, 0 },
	{  1, 1, 1, 1, 0, 0 },
};
char MAP[15][15];
int DP[15][15];

bool unsafe(int n, int m) { return n < 0 || m < 0 || n >= N || m >= M; }
int solve(int n, int m) {
	if (unsafe(n, m)) return 0;
	if (VIS[n][m] == 1) return 0;
	VIS[n][m] = 1;

	int result = 0;
	for (int i = 0; i < 4; i++) {
		int nn = n + AY[i], nm = m + AX[i];
		// dfs
		if (unsafe(nn, nm)) continue;
		if (VIS[nn][nm] == 1) continue;

		// 현재 칸을 버리고 다음 두부부터 자를 경우
		int drop = solve(nn, nm);
		result = max(result, drop);

		// 현재 칸을 안 버리고 자를 경우
		VIS[nn][nm] = 1;

		// 다음 두부 자르기
		for (int j = 0; j < 4; j++) {
			int next = solve(nn+AY[j], nm+AX[j]) + SCORE[MAP[n][m]-'A'][MAP[nn][nm]-'A'];
			if (DP[nn+AY[j]][nm+AX[j]] >= next) continue;
			DP[nn+AY[j]][nm+AX[j]] = next;

			result = max(result, next);
		}

		VIS[nn][nm] = 0;
	}

	VIS[n][m] = 0;
	return DP[n][m] = result;
}

int main() {
	for (int i = 0; i < 15; i++) for (int j = 0; j < 15; j++) DP[i][j] = -1;

	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> MAP[i][j];

	cout << solve(0, 0) << endl;
	return 0;
}
