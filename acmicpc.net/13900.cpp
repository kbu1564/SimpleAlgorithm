#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long ARR[100001];
int S[100001];
int main() {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &ARR[i]);
	sort(ARR + 1, ARR + N + 1);
	for (int i = 1; i <= N; i++) S[i] = S[i-1] + ARR[i];

	long long result = 0;
	for (int i = 1; i <= N; i++) {
		result += ARR[i] * (S[N] - S[i]);
	}

	printf("%lld\n", result);
	return 0;
}
