#include <iostream>
#include <algorithm>
using namespace std;
int A[501][501];
int DP[501][501];
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j <= i; j++) cin >> A[i][j];

	DP[0][0] = A[0][0];
	for (int i = 1; i < N; i++) for (int j = 0; j <= i; j++) {
		DP[i][j] = max(DP[i-1][j] + A[i][j], DP[i-1][j-1] + A[i][j]);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) ans = max(ans, DP[N-1][i]);
	cout << ans << endl;
	return 0;
}
