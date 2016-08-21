#include <iostream>
using namespace std;
long long MAP[101][101];
long long DP[101][101] = { { 0, }, { 0, 1, }, };
int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> MAP[i][j];

	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		if (MAP[i][j] <= 0) continue;
		if (i + MAP[i][j] <= N && DP[i][j] > 0) DP[i + MAP[i][j]][j] += DP[i][j];
		if (j + MAP[i][j] <= N && DP[i][j] > 0) DP[i][j + MAP[i][j]] += DP[i][j];
	}

	cout << DP[N][N] << endl;
	return 0;
}
