#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long long IT[3000001];
void update(int i, long long k) {
	int curr = i;
	long long addN = k - IT[curr];
	IT[curr] = k;
	while (curr > 0) {
		IT[curr/2] += addN;
		curr /= 2;
	}
}

long long sum(int s, int e, int S, int E, int p) {
	if (s > E || e < S) return 0;
	if (s >= S && e <= E) return IT[p];
	return sum(s, (s+e)/2, S, E, p*2) + sum((s+e)/2+1, e, S, E, p*2+1);
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int Q = M + K;
	int P = 1 << (int)ceil(log2(N));

	for (int i = P; i < P + N; i++) {
		int n; scanf("%d", &n);
		update(i, n);
	}
	
	for (int i = 0; i < Q; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		if (A == 1) {
			update(P + B - 1, C);
		}
		if (A == 2) {
			printf("%lld\n", sum(1, P, B, C, 1));
		}
	}
	return 0;
}
