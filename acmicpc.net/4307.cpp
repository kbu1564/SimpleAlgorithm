#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int ARR[100001];
int main() {
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int N, L; scanf("%d %d", &L, &N);
		for (int i = 1; i <= N; i++) scanf("%d", &ARR[i]);

		int minResult = 0, maxResult = 0;
		for (int i = 1; i <= N; i++) {
			int dmin = min(abs(L - ARR[i]), abs(ARR[i]));
			minResult = max(minResult, dmin);

			int dmax = max(abs(L - ARR[i]), abs(ARR[i]));
			maxResult = max(maxResult, dmax);
		}

		printf("%d %d\n", minResult, maxResult);
	}
	return 0;
}
