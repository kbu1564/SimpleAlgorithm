#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int T, M;
long long IN[100001];
long long gcd(long long a, long long b) { return !a? b: gcd(b%a, a); }
inline long long _max(long long a, long long b) { return a > b? a: b; }
inline long long _min(long long a, long long b) { return a > b? b: a; }

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			scanf("%lld", &IN[j]);
		}

		int zeroCount = 0;
		// 최대 공차 : gcd(... gcd(gcd(IN[1]-IN[0], IN[2]-IN[1]), IN[3]-IN[2]), ...), IN[M-1]-IN[M-2])
		long long d = IN[1] - IN[0];
		for (int j = 1; j < M; j++) {
			if (IN[j] - IN[j-1] == 0) zeroCount++;
			long long in_min = min(d, IN[j] - IN[j-1]);
			long long in_max = max(d, IN[j] - IN[j-1]);
			if (in_min + in_max > 0)
				d = gcd(in_min, in_max);
		}

		int result = 0;
		long long sqt = sqrt(d) + 1;
		for (long long i = 1; i <= sqt; i++) {
			if (d % i == 0) {
				if (i == d / i) result--;
				if (i > d / i) break;
				result += 2;
			}
		}

		// 공차가 0인 경우 포함
		if (d == 0 && zeroCount > 0) result++;

		printf("Case #%d\n", i);
		printf("%d\n", d > 0 && zeroCount > 0? 0: result);
	}
	return 0;
}
