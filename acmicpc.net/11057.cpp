#include <iostream>
#include <algorithm>
using namespace std;
int DP[1001][10];
int main() {
	int N; cin >> N;
	for (int i = 0; i < 10; i++) DP[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				DP[i][j] = (DP[i][j] + DP[i-1][k]) % 10007;
			}
		}
	}
	int result = 0;
	for (int j = 0; j < 10; j++) result = (result + DP[N][j]) % 10007;
	cout << result << endl;
	return 0;
}
