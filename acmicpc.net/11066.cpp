#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int SUM[501];
int DP[501][501], F[501], T, K;
int solve(int s, int e) {
	if (e < s || s < 0 || e < 0) return 0;
	if (DP[s][e] < INF) return DP[s][e];
	if (s == e) return DP[s][e] = F[s];

	for (int i = s; i < e; i++) {
		int t1 = solve(s, i);
		int t2 = solve(i+1, e);
		int tr = (SUM[e] - (s > 0? SUM[s-1]: 0)) + (s == i? 0: t1) + (i+1 == e? 0: t2);
		DP[s][e] = min(DP[s][e], tr);
	}
	return DP[s][e];
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> K;
		for (int j = 0; j < 501; j++) for (int k = 0; k < 501; k++) DP[j][k] = INF;
		for (int j = 0; j < K; j++) {
			cin >> F[j];
			SUM[j] = (j > 0? SUM[j-1]: 0) + F[j];
		}
		cout << solve(0, K-1) << endl;
	}
	return 0;
}
