#include <cstdio>
#include <iostream>
using namespace std;

int ADJ[501][501] = { 0, };
int MAP[501][501] = { 0, };
int main() {
	int T; scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		int BACK[501] = { 0, };
		int COIN[501] = { 0, };
		int N, M; scanf("%d %d", &N, &M);
		for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) MAP[i][j] = 0, ADJ[i][j] = 1e9;
		for (int i = 0; i < M; i++) {
			int va, vb; scanf("%d %d", &va, &vb);
			//MAP[va][vb] = MAP[vb][va] = 1;
			ADJ[va][vb] = ADJ[vb][va] = 1;
		}

		for (int i = 1; i <= N; i++) ADJ[i][i] = 0;
		// 0 : 검정, 1 : 하양
		for (int i = 1; i <= N; i++) scanf("%d", &BACK[i]);
		for (int i = 1; i <= N; i++) scanf("%d", &COIN[i]);

		// floyd
		for (int k = 1; k <= N; k++)
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					if (ADJ[i][j] > ADJ[i][k] + ADJ[k][j])
						ADJ[i][j] = ADJ[i][k] + ADJ[k][j];

		int result = 0;
		int blackIdx = 0;
		for (int i = 1; i <= N; i++) { // 동전 위치
			if (BACK[i] == 0) {
				if (COIN[i] == 0) continue;

				// 다음 검은 동전 위치 찾기
				for (; blackIdx <= N && (BACK[blackIdx] != 1 || COIN[blackIdx] != 0); blackIdx++);
				if (COIN[blackIdx] == 0) result += ADJ[i][blackIdx];

				blackIdx++;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
