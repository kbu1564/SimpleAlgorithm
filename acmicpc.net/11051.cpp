#include <iostream>
using namespace std;
int MOD = 10007;
int FACT[1001] = { 1, };
int DP[1001][1001];
int combi(int n, int k) {
	if (n < 1 || k < 1 || n < k) return 1;
	if (DP[n][k] > 0) return DP[n][k];
	if (n == k) return DP[n][k] = 1;
	if (n == k + 1) return DP[n][k] = n;
	//if (k == 1) return DP[n][k] = FACT[n];
	return DP[n][k] = (combi(n-1, k-1) + combi(n-1, k)) % MOD;
}
int main() {
	for (int i = 1; i < 1001; i++) {
		FACT[i] = (FACT[i-1] * i) % MOD;
	}

	int N, K;
	cin >> N >> K;
	cout << combi(N, K) << endl;
	return 0;
}

