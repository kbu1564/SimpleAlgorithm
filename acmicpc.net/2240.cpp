#include <iostream>
#include <algorithm>
using namespace std;

// DP[i][j][k] = i초때 자두가 j번 이동하여 k나무 아래에 있을때 받을 수 있는 자두의 개수
int DP[1001][31][3];
int ARR[1001];

int main() {
	int T, W; cin >> T >> W;
	for (int i = 1; i <= T; i++) cin >> ARR[i];

	//if (ARR[1] == 1) DP[1][0][1] = 1;
	//if (ARR[1] == 2) DP[1][1][2] = 1;

	for (int i = 1; i <= T; i++) {
		for (int j = 0; j <= W; j++) {
			// DP[i][j][1] = i-1초때 1번 나무 아래 있었을 경우와 i-1초때 2번 나무 아래 있었을 경우중 최대값 + 1
			if (ARR[i] == ARR[i-1]) {
				DP[i][j][ARR[i]] = max(DP[i][j][ARR[i]], DP[i-1][j][ARR[i]] + 1);
			} else {
				DP[i][j][ARR[i]] = max(DP[i][j][ARR[i]], DP[i-1][j][ARR[i]]);
				if (3-ARR[i] == 1 || (3-ARR[i] == 2 && j > 0))
					DP[i][j][ARR[i]] = max(DP[i][j][ARR[i]], DP[i-1][j-1][3-ARR[i]] + 1);
			}
		}
	}

	for (int i = 1; i <= T; i++) {
		for (int j = 0; j <= W; j++) {
			cout << i << " = " << j << " : " << DP[i][j][1] << " " << DP[i][j][2] << endl;
		}
	}

	int result = 0;
	for (int j = 0; j <= W; j++) result = max(result, max(DP[T][j][1], DP[T][j][2]));

	cout << result << endl;
	return 0;
}
