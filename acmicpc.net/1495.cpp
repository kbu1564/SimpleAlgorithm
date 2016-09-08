#include <iostream>
#include <algorithm>
using namespace std;

int N, S, M;
int DP[1001][101];
int ARR[101];
int solve(int s, int idx) {
	if (s < 0 || s > M) return DP[s][idx] = s;
	if (DP[s][idx] > -1e9) return DP[s][idx];
	if (idx > N) return s;
	return DP[s][idx] = max(solve(s + ARR[idx], idx + 1), solve(s - ARR[idx], idx + 1));
}
int main() {
	cin >> N >> S >> M;
	for (int i = 0; i < 1001; i++) for (int j = 0; j < 101; j++) DP[i][j] = -1e9;
	for (int i = 1; i <= N; i++) cin >> ARR[i];
	int result = solve(S, 1);
	cout << (result < 0 || result > M? -1: result) << endl;
	return 0;
}
