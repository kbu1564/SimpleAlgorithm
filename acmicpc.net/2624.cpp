#include <cstdio>
#include <iostream>
using namespace std;

int DP[10001] = { 1, };
int P[101], N[101];
int main() {
	int T; scanf("%d", &T);
	int K; scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int p, n; scanf("%d %d", &p, &n);
		P[i] = p;
		N[i] = n;
	}

	for (int i = 0; i < K; i++) {
		for (int j = T; j >= 1; j--) {
			for (int k = 1; k <= N[i] && j >= P[i] * k; k++) {
				DP[j] += DP[j - P[i] *k];
			}
		}
	}

	printf("%d\n", DP[T]);
	return 0;
}
