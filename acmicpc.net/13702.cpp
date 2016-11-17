#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long ARR[10001];
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%lld", &ARR[i]);

	long long s = 0;
	long long e = 1e10;
	long long ans = 0;
	while (s + 1 < e) {
		int result = 0;
		long long m = (s + e) / 2;
		for (int i = 0; i < N; i++) result += ARR[i] / m;

		if (result >= K) {
			s = m;
			ans = max(ans, m);
		} else {
			e = m;
		}
	}

	printf("%lld\n", ans);
	return 0;
}
