#include <iostream>
using namespace std;
int DP[1001][10] = { { 0, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, };
int main() {
	int N; cin >> N;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				DP[i][j] = (DP[i][j] + DP[i-1][k]) % 10007;
			}
		}
	}
	int rst = 0;
	for (int i = 0; i < 10; i++) rst = (rst + DP[N][i]) % 10007;
	cout << rst << endl;
	return 0;
}
