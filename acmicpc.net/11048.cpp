#include <iostream>
using namespace std;
int DP[1001][1001];
int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> DP[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int xy = 0, x = 0, y = 0;
			if (i > 0 && j > 0) xy = DP[i-1][j-1];
			if (i > 0) y = DP[i-1][j];
			if (j > 0) x = DP[i][j-1];
			DP[i][j] = DP[i][j] + max(xy, max(x, y));
		}
	}
	cout << DP[N-1][M-1] << endl;
	return 0;
}
