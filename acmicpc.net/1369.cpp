#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int ARR[1001][1001];
int DP[2][1001][1001];
int f(int i, int j, int d) {
	int idx = d == 2? 0: 1;
	if (i < 1 || j < 1) return 0;
	if (ARR[i][j] == 0) return 1e9;
	if (DP[idx][i][j] > 0) return DP[idx][i][j];
	int result = 0;
	int c = ARR[i][j];
	while (c > 0 && c % d == 0) {
		result++;
		c /= d;
	}
	if (i > 1 && j > 1) result += min(f(i-1, j, d), f(i, j-1, d));
	if (i > 1 && j < 2) result += f(i-1, j, d);
	if (i < 2 && j > 1) result += f(i, j-1, d);
	return DP[idx][i][j] = result;
}
int main() {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &ARR[i][j]);
		}
	}
	
	printf("%d\n", min(f(N, N, 2), f(N, N, 5)));
	return 0;
}

