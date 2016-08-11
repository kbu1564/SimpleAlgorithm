#include <iostream>
#include <cmath>
using namespace std;
int main() {
	// sqrt(N)

	long long N, K; cin >> N >> K;

	long long result = 0;
	// K % N ~ K % (K + 1)
	if (N > K) result += (N - K) * K;

	//  K % K ~ K % (K/2) 까지의 합
	result += (K / 2LL + K % 2LL - 1LL) * ((K / 2LL + K % 2LL - 1LL) + 1LL) / 2LL;

	// K % (K/2-1) ~ K % 1 까지의 합
	int half = K / 2;
	long long sqrtK = sqrt(K) + 1;
	for (int i = 2; i < half / 2; i++) {
		int first = K % i;
		for (int j = i; j < half; j+=j) {
			//cout << K << " % " << j << " = " << first << endl;
			result += first;
		}
	}

	for (int i = half / 2 + 1; i < half; i+=2) {
		result += K % i;
	}

	cout << result << endl;
	return 0;
}
// 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 - K / 2
// x x x x x x x x  x  x  x  x  x  x  x     x     x     x     x     x     x     x     x
