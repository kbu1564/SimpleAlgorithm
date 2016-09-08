#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int TEAM[100001], CYCLE[100001];
int P[100001];
int main() {
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N; scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			scanf("%d", &P[j]);
			if (j == P[j]) {
				TEAM[j] = 1;
			} else {
				TEAM[j] = 0;
			}
		}
		
		int accept = 0;
		int result = 0;
		for (int j = 1; j <= N; j++) {
			if (CYCLE[j] > 0) continue;
			
			int acceptCount = 0;
			int curr = P[j];
			TEAM[j] = 1;
			while (true) {
				if (TEAM[curr] != 0) break;
				if (curr == j) break;
				acceptCount++;
				TEAM[curr] = 1;
				curr = P[curr];
			}
			
			if (curr != j && P[curr] != j) {
				result++;
			} else {
				accept += acceptCount;
				int curr = P[j];
				CYCLE[j] = 1;
				while (true) {
					if (CYCLE[curr] != 0) break;
					if (curr == j) break;
					CYCLE[curr] = 1;
					curr = P[curr];
				}
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
