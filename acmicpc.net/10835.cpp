#include <cstdio>
#include <iostream>
using namespace std;
int N;
int A[2002];
int B[2002];
int DP[2001][2001];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];

	int rst = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			DP[i][j] = max(DP[i][j], DP[i-1][j]);
			DP[i][j] = max(DP[i][j], DP[i-1][j-1]);
			if (A[i] > B[j]) {
				if (DP[i][j-1] >= 0)
					DP[i][j] = max(DP[i][j], DP[i][j-1] + B[j]);
			} else {
				DP[i][j] = -1;
			}
			rst = max(rst, DP[i][j]);
		}
	}

	cout << rst << endl;
	return 0;
}

