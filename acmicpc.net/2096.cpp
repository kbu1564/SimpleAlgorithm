#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int MAXDP[100001][3];
int MINDP[100001][3];
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		MAXDP[i][0] = MINDP[i][0] = a;
		MAXDP[i][1] = MINDP[i][1] = b;
		MAXDP[i][2] = MINDP[i][2] = c;
	}

	for (int i = 1; i < N; i++) {
		MAXDP[i][0] += max(MAXDP[i-1][0], MAXDP[i-1][1]);
		MAXDP[i][1] += max(MAXDP[i-1][0], max(MAXDP[i-1][1], MAXDP[i-1][2]));
		MAXDP[i][2] += max(MAXDP[i-1][1], MAXDP[i-1][2]);

		MINDP[i][0] += min(MINDP[i-1][0], MINDP[i-1][1]);
		MINDP[i][1] += min(MINDP[i-1][0], min(MINDP[i-1][1], MINDP[i-1][2]));
		MINDP[i][2] += min(MINDP[i-1][1], MINDP[i-1][2]);
	}

	cout << max(MAXDP[N-1][0], max(MAXDP[N-1][1], MAXDP[N-1][2])) << " ";
	cout << min(MINDP[N-1][0], min(MINDP[N-1][1], MINDP[N-1][2])) << endl;
	return 0;
}
