#include <iostream>
using namespace std;
int A[10001], DP[10001][3];
int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			DP[i][1] = A[i];
		} else {
			DP[i][0] = max(DP[i-1][0], max(DP[i-1][1], DP[i-1][2]));
			DP[i][1] = DP[i-1][0] + A[i];
			DP[i][2] = DP[i-1][1] + A[i];
		}
	}

	cout << max(DP[N][0], max(DP[N][1], DP[N][2])) << endl;
	return 0;
}
