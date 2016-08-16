#include <algorithm>
#include <iostream>
using namespace std;
int N;
int A[2002];
int B[2002];
int DP[2002][2002];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0) DP[i][j] = -1;
			if (j == 0) DP[i][j] = -1;
		}
	}

	int rst = 0;
	for (int i = 1; i <= N+1; i++) {
		for (int j = 1; j <= N+1; j++) {
			DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]);
			if (A[i] > B[j - 1]) {
				DP[i][j] = max(DP[i][j], DP[i][j - 1] + B[j - 1]);
			}
			rst = max(rst, DP[i][j]);
		}
	}

	cout << rst << endl;
	return 0;
}
