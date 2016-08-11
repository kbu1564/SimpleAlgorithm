#include <iostream>
using namespace std;
long long DP[16][16];
int main() {
	int N, M, K; cin >> N >> M >> K;
	int x = (K-1) % M;
	int y = (K-1) / M;
	if (K == 0) {
		x = M;
		y = N;
	}
	for (int i = 0; i <= y; i++) {
		for (int j = 0; j <= x; j++) {
			DP[i][j] = (i-1 < 0? 0: DP[i-1][j]) + (j-1 < 0? 0: DP[i][j-1]);
			if (i == 0 && j == 0) DP[i][j] = 1;
		}
	}
	for (int i = y; i < N; i++) {
		for (int j = x; j < M; j++) {
			DP[i][j] = (i-1 < 0? 0: DP[i-1][j]) + (j-1 < 0? 0: DP[i][j-1]);
		}
	}
	cout << DP[N-1][M-1] << endl;
	return 0;
}
