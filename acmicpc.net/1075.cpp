#include <iostream>
#include <algorithm>
using namespace std;
int DP[101];
int main() {
	int N, F; cin >> N >> F;
	int h00 = N - (N % 100);
	DP[0] = DP[1] = 0;
	for (int i = 1; i < 101; i++) {
		DP[i] = 99;
		for (int j = h00; j < h00 + 100; j++) {
			if (j % i == 0) {
				DP[i] = min(DP[i], j % 100);
			}
		}
	}
	cout << (char)(DP[F] / 10 + '0') << (char)(DP[F] % 10 + '0') << endl;
	return 0;
}
