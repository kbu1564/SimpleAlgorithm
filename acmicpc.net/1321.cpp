#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int CC[1100001];
int NC[1100001];
int find(int s, int e, int S, int E, int p) {
	if (s > E || e < S) return 0;
	if (s >= S && e <= E) return NC[p];
	return find(s, (s+e)/2, S, E, p*2) + find((s+e)/2+1, e, S, E, p*2+1);
}
// NC를 SDC개 단위로 평방분할
int main() {
	int N; scanf("%d", &N);

	int P = 1;
	while (P < N) P *= 2;

	for (int i = P; i < P + N; i++) {
		scanf("%d", &NC[i]);
		CC[i] = 1;
		int curr = i / 2;
		while (curr > 0) {
			NC[curr] += NC[i];
			CC[curr] += CC[i];
			curr /= 2;
		}
	}
	int M; scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int C, I, A;
		scanf("%d", &C);
		if (C == 1) {
			// 증.감설
			scanf("%d %d", &I, &A);
			int curr = P + I - 1;
			while (curr > 0) {
				NC[curr] += A;
				curr /= 2;
			}
		}
		if (C == 2) {
			// i번째 소속 구하기
			scanf("%d", &I);

			int curr = 1;
			while (NC[curr] > I) curr *= 2;

			if (curr * 2 < P) curr *= 2;
			int total = NC[curr];
			int result = CC[curr];
			int rcurr = curr + 1;
			while (rcurr < P) rcurr *= 2;
			while (total < I) {
				total += NC[rcurr];
				result++;
				rcurr++;
			}
			cout << result << endl;
		}
	}
	return 0;
}
