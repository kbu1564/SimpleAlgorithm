#include <cstdio>
#include <iostream>
using namespace std;
int A[101];
long long DP[21][101];
long long solve(int eq, int idx) {
	if (idx < 0) return 0;
	if (idx == 0) return DP[eq][idx] = (eq == A[idx]);
	if (DP[eq][idx] > 0) return DP[eq][idx];
	long long rst = 0;
	int r1 = eq - A[idx];
	int r2 = eq + A[idx];
	if (r1 >= 0 && r1 <= 20) rst += solve(r1, idx-1);
	if (r2 >= 0 && r2 <= 20) rst += solve(r2, idx-1);
	return DP[eq][idx] = rst;
}
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	printf("%lld\n", solve(A[N-1], N-2));
	return 0;
}
