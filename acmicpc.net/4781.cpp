#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int DP[10001];
int N[5001], M[5001];
int main() {
	int n, m;
	double temp;
	for (; scanf("%d %lf", &n, &temp), n != 0 && temp != 0.0;) {
		m = round(temp * 10000.0 / 100.0);
		for (int j = 0; j < 10001; j++) DP[j] = 0;

		for (int i = 1; i <= n; i++) {
			int c = 0;
			double p = 0.0;
			scanf("%d %lf", &c, &p);
			N[i] = c;
			M[i] = round(p * 10000.0 / 100.0);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (M[i] <= j)
					DP[j] = max(DP[j], DP[j - M[i]] + N[i]);
			}
		}
		printf("%d\n", DP[m]);
	}
	return 0;
}
