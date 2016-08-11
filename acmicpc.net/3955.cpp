#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int t, k, c;
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &k, &c);
		if (gcd(k, c) != 1) {
			printf("IMPOSSIBLE\n");
		} else {
			// kx + 1 = cy;
			long long q, r, s, t;
			long long r1 = k, r2 = c;
			long long s1 = 1, s2 = 0;
			long long t1 = 0, t2 = 1;
			while (r2 > 0) {
				q = r1 / r2;

				r = r1 - r2 * q;
				r1 = r2;
				r2 = r;

				s = s1 - s2 * q;
				s1 = s2;
				s2 = s;

				t = t1 - t2 * q;
				t1 = t2;
				t2 = t;
			}

			while (t1 < 0 || t2 < 0) {
				// k*t2 = c*t1 - 1
				// x = t2, y = t1;
				while (t1 < 0) t1 += k;
				t2 = (c * t1 - 1) / k;
			}

			if (t1 > 1000000000) printf("IMPOSSIBLE\n");
			else printf("%lld\n", t1);
		}
	}
	return 0;
}
