#include <iostream>
#include <algorithm>
using namespace std;
int P[1001];
int DP[1001];
int dp(int N) {
	if (N <= 0) return N;
	if (DP[N] > 0) return DP[N];

	for (int i = 1; i <= N; i++) {
		DP[N] = max(DP[N], dp(N - i) + P[i]);
	}

	return DP[N];
}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	cout << dp(N) << endl;
	return 0;
}
