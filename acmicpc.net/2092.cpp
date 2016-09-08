#include <iostream>
using namespace std;

const int MOD = 1e6;

int DP[4001] = { 1, };
int ARR[201];
int main() {
	ios::sync_with_stdio(false);

	int T, A, S, B;
	cin >> T >> A >> S >> B;

	for (int i = 0, x = 0; i < A; i++) {
		cin >> x;
		ARR[x]++;
	}

	for (int i = 1; i <= T; i++) {
		for (int j = B; j >= 1; j--) {
			for (int k = 1; k <= ARR[i] && j >= k; k++) {
					DP[j] = (DP[j] + DP[j-k]) % MOD;
			}
		}
	}

	int result = 0;
	for (int i = S; i <= B; i++) result = (result + DP[i]) % MOD;
	cout << result << endl;
	
	return 0;
}
