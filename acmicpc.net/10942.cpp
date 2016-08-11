#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ARR[2001];
int DP[2001][2001];
int solve(int s, int e) {
	if (s >= e) return ARR[s] == ARR[e];
	if (DP[s][e] > 0) return DP[s][e];
	if (ARR[s] == ARR[e]) return DP[s][e] = solve(s+1, e-1);
	return 0;
}
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &ARR[i]);
	int M; scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int S, E; scanf("%d %d", &S, &E);
		printf("%d\n", solve(S - 1, E - 1));
	}
	return 0;
}
