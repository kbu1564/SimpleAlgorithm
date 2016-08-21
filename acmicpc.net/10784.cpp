#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int p, a, b, c, d, n;
double DP[1000001];
inline double price(int k) { return p * (sin(a * k + b) + cos(c * k + d) + 2.0); }

int main() {
	cin >> p >> a >> b >> c >> d >> n;

	for (int i = 1; i <= n; i++) {
		DP[i] = max(DP[i-1], price(i));
	}

	double result = 0.0;
	for (int i = 2; i <= n; i++) {
		result = max(result, DP[i] - price(i));
	}

	printf("%.20lf\n", result);
	return 0;
}
