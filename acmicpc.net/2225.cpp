
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int DP[201][201];
int main() {
	int N, K; cin >> N >> K;

	// 1장으로 0 ~ N 만드는 경우는 각 1개씩
	for (int i = 0; i <= N; i++) DP[i][1] = 1;
	for (int i = 0; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			for (int l = 0; l <= i; l++) {
				DP[i][j] = (DP[i][j] + DP[l][j - 1]) % 1000000000;
			}
		}
	}

	cout << DP[N][K] << endl;
	return 0;
}
/*
#include <cstdio>

int n, k, dp[201] = { 1 };
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
			dp[j] = (dp[j - 1] + dp[j]) % (int)(1e9);

    printf("%d", dp[n]);
    return 0;
}
*/