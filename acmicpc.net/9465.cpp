#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int DP[2][100001], M[2][100001]; // DP[i][j] = 맨 마지막에 (j, i)의 스티커를 떼었을 경우의 최대 점수
int main() {
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N; scanf("%d", &N);
		for (int y = 0; y < 2; y++) for (int x = 0; x < N; x++) {
			scanf("%d", &M[y][x]);
			DP[y][x] = M[y][x];
		}

		for (int x = 0; x < N; x++) {
			int b1 = 0, b2 = 0, b3 = 0;

			b1 = x > 0? DP[0][x-1]: 0;
			b2 = x > 1? DP[0][x-2]: 0;
			b3 = x > 1? DP[1][x-2]: 0;
			DP[1][x] = max(b1, max(b2, b3)) + M[1][x];

			b1 = x > 0? DP[1][x-1]: 0;
			b2 = x > 1? DP[1][x-2]: 0;
			b3 = x > 1? DP[0][x-2]: 0;
			DP[0][x] = max(b1, max(b2, b3)) + M[0][x];
		}
		cout << max(DP[0][N-1], DP[1][N-1]) << endl;
	}
	return 0;
}
