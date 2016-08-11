#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int DP[101];
int MM[2] = { INF, INF };
int dp(int N) {
	if (N <= 0) return 0;
	if (N == 6) return MM[0];
	if (N == 1) return MM[1];
	if (DP[N] >= 0) return DP[N];
	return DP[N] = min(dp(N-6)+MM[0], dp(N-1)+MM[1]);
}
int main() {
	int N, M;
	cin >> N >> M;
	memset(DP, -1, sizeof(DP));
	for (int i = 0; i < M; i++) {
		int p6, p1;
		cin >> p6 >> p1;
		MM[0] = min(MM[0], p6);
		MM[1] = min(MM[1], p1);
	}
	// 1. DP[N] = N개의 끊어진 줄을 사기위한 최소 금액
	// 2. DP[N] = min(DP[N-6]+M[0], DP[N-1]+M[1]);
	// M[0] = 6개의 패키징 가격중 최소 금액
	// M[1] = 1개 낱개 가격중 최소 금액
	cout << dp(N) << endl;
	return 0;
}
