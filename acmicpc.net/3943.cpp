#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int result = 1;
int DP[1000001] = { 0, 1, };
void solve(int n) {
	if (n == 1) return;
	//if (n < 100001 && DP[n] > 0) return;

	result = max(result, n);
	if (n % 2 == 0) solve(n/2);
	else solve(n*3+1);

	//if (n < 100001)
	//	DP[n] = result;
}
int main() {
	int T; scanf("%d", &T);
	for (int i = 1; i < 100001; i++) {
		solve(i);
		DP[i] = result;
		result = 0;
	}
	for (int i = 0; i < T; i++) {
		int N; scanf("%d", &N);
		printf("%d\n", DP[N]);
	}
	return 0;
}
