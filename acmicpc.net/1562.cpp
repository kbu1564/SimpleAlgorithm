#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9;
long long DP[101][10][1024];
// DP[i][j][k] = i자리 계단수 중 맨 처음 자리가 j이면서 0~9까지 한번씩 등장한 상태가 k인 계단수의 개수

int main() {
	int N; cin >> N;

	for (int i = 0; i < 10; i++) DP[1][i][1<<i] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1024; k++) {
				int nk = k | (1 << j);
				if (j == 0)
					DP[i][j][nk] = (DP[i][j][nk] + DP[i-1][1][k]) % MOD;
				else if (j == 9)
					DP[i][j][nk] = (DP[i][j][nk] + DP[i-1][8][k]) % MOD;
				else
					DP[i][j][nk] = (DP[i][j][nk] + DP[i-1][j-1][k] + DP[i-1][j+1][k]) % MOD;
			}
		}
	}

	long long result = 0;
	for (int j = 1; j < 10; j++) {
		result += DP[N][j][1023];
		result %= MOD;
	}
	
	cout << result << endl;
	return 0;
}

