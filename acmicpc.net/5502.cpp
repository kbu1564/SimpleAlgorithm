#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int INF = 1e9;
int N, DP[5001][5001];
string S;
int solve(int left, int right) {
	if (left >= right) return 0;
	if (DP[left][right] < 1e9) return DP[left][right];
	if (S[left] == S[right]) return solve(left + 1, right - 1);
	int ll = solve(left + 1, right) + 1;
	int rr = solve(left, right - 1) + 1;
	return DP[left][right] = min(ll, rr);
}
int main() {
	cin >> N;
	cin >> S;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			DP[i][j] = INF;

	cout << solve(0, S.length() - 1) << endl;
	return 0;
}
