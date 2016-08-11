#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 100000;
int Q[SIZE];
int MAP[1001][1001];
int main() {
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, K, TRR[1001] = { 0, };
		int INARR[1001] = { 0, };
		scanf("%d %d", &N, &K);
		for (int j = 1; j <= N; j++) scanf("%d", &TRR[j]);
		for (int j = 1; j <= K; j++) {
			int u, v;
			scanf("%d %d", &u, &v);
			MAP[u][v] = 1;
			INARR[v]++;
		}
		int W; scanf("%d", &W);

		// IN 0개 삽입
		int f = 0, r = 0;
		Q[r++] = W;
		r %= SIZE;
		// bfs
		while (r != f) {
			int data = Q[f++];
			f %= SIZE;

			for (int j = 1; j <= N; j++) {
				if (MAP[j][data] == 1) {
					// 최대값 구하기
				}
			}
		}
	}
	return 0;
}

