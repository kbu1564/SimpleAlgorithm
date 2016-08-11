#include <cstdio>
#include <iostream>
using namespace std;
const long long INF = 987654321;
long long DP[101][101];
int main() {
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++) DP[i][j] = INF;
	for (int i = 1; i <= N; i++) DP[i][i] = 0;
	for (int i = 0; i < M; i++) {
		long long va, vb, e;
		scanf("%lld %lld %lld", &va, &vb, &e);
		DP[va][vb] = min(DP[va][vb], e);
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (DP[i][j] > DP[i][k] + DP[k][j])
					DP[i][j] = DP[i][k] + DP[k][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%lld ", DP[i][j] == INF? 0: DP[i][j]);
		printf("\n");
	}
	return 0;
}
