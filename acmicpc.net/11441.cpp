#include <cstdio>
#include <iostream>
using namespace std;
int A[100001];
int S[100001];
int main() {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]), S[i] = S[i-1] + A[i];
	int M; scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", S[b] - S[a-1]);
	}
	return 0;
}
