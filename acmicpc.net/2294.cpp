#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
const int INF = 987654321;
int n,k,N[101],DP[10001];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i < 10001; i++) DP[i] = INF;
	for (int i = 0; i < n; i++) {
		scanf("%d", &N[i]);
		if (N[i] >= 0 && N[i] <= k) DP[N[i]] = 1;
	}
	// DP[i] = i원을 만들기 위한 최소 동전 수
	for (int i = 0; i <= k; i++)
		for (int j = 0; j < n; j++)
			if (i-N[j] >= 0)
				DP[i] = min(DP[i], DP[i-N[j]] + 1);

	cout << (DP[k] >= INF? -1: DP[k]) << endl;
	return 0;
}

