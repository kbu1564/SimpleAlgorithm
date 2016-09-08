#include <iostream>
using namespace std;

const int MOD = 1e9;
int DP[1000001] = { 1, };

int main() {
	int N; cin >> N;

	for (int i = 1; i <= N; i*=2) {
		for (int j = i; j <= N; j++) {
			DP[j] = (DP[j] + DP[j-i]) % MOD;
		}
	}
	cout << DP[N] << endl;
	return 0;
}
