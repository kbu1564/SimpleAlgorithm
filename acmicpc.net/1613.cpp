#include <cstdio>

int DP[401][401];
int main() {
	int N, K; scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int va, vb; scanf("%d %d", &va, &vb);
		DP[va][vb] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (DP[i][k] == 1 && DP[k][j] == 1)
					DP[i][j] = 1;

	int S; scanf("%d", &S);
	for (int i = 0; i < S; i++) {
		int va, vb; scanf("%d %d", &va, &vb);
		if (DP[va][vb] == 1) {
			printf("-1\n");
		} else if (DP[vb][va] == 1) {
			printf("1\n");
		} else {
			printf("0\n");
		}
	}
	return 0;
}
