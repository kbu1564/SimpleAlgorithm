#include <cstdio>
#include <iostream>
using namespace std;

int N, M;
int IT[300001];
int find(int s, int e, int S, int E, int p) {
	if (s > E || e < S) return 1e9;
	if (s >= S && e <= E) return IT[p];
	return min(find(s, (s+e)/2, S, E, p*2), find((s+e)/2+1, e, S, E, p*2+1));
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < 300001; i++) IT[i] = 1e9;

	int P = 1;
	while (P < N) P *= 2;

	for (int i = P; i < P + N; i++) {
		scanf("%d", &IT[i]);

		int curr = i;
		while (curr / 2 > 1) {
			IT[curr/2] = min(IT[curr/2], IT[curr]);
			curr /= 2;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b; scanf("%d %d", &a, &b);
		printf("%d\n", find(1, P, a, b, 1));
	}
	return 0;
}
