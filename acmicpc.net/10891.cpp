#include <cstdio>

int P[100001];
int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i <= N; i++) P[i] = i;
	for (int i = 0; i < M; i++) {
		int X, Y; scanf("%d %d", &X, &Y);
		P[Y] = X;
	}
	for (int i = 1; i <= N; i++) {
		
	}
	return 0;
}
