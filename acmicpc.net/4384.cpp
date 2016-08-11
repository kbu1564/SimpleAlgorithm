#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N, total;
int W[101];
int DP[101][45001] = { 1, }; // DP[i][j] = i개를 사용하여 j를 만드는 것이 가능한지?
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> W[i];
		total += W[i];
	}

	// total / 2 에 최대한 근접해야함
	int result = 0;
	int rhalf = 0;
	int half = total / 2;
	for (int i = 0; i < N; i++) {
		int ihalf = min(i + 1, N / 2 + N % 2);
		for (int j = 0; j < ihalf; j++) {
			//if (N - i + j < N / 2) continue;

			int whalf = min(rhalf, half);
			for (int k = 0; k <= whalf; k++) {
				if (DP[j][k] == 1 && k + W[i] <= half) {
					DP[j + 1][k + W[i]] = 1;
					if ((j + 1 == N / 2) || (j + 1 == N / 2 + N % 2))
						result = max(result, k + W[i]);
				}
			}
		}
		rhalf += W[i];
	}
	cout << result << " " << total - result << endl;
	
	return 0;
}
