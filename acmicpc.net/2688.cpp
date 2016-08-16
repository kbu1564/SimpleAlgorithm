#include <iostream>
using namespace std;
long long DP[64][10];
int main() {
	int T; cin >> T;
	for (int i = 0; i < 10; i++) DP[1][i] = 1;
	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				DP[i][j] += DP[i-1][k];
			}
		}
	}
	for (int i = 0; i < T; i++) {
		int N; cin >> N;

		long long result = 0;
		for (int j = 0; j < 10; j++) result += DP[N][j];
		cout << result << endl;
	}
	return 0;
}
