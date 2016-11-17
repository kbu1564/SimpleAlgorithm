#include <iostream>
#include <algorithm>
using namespace std;

long long ARR[36];
long long t(int n) {
	if (n <= 1) return 1;
	if (ARR[n] > 0) return ARR[n];
	for (int i = 1; i <= n/2; i++) {
		ARR[n] += 2 * t(i-1) * t(n-i);
	}
	if (n % 2 == 1) ARR[n] += t(n/2) * t(n/2);
	return ARR[n];
}
int main() {
	// t(n) = t(0) * t(n-1) + t(1) * t(n-2) ... t(n-1) * t(0);
	// t(n) = 2 * t(0) * t(n-1) + 2 * t(1) * t(n-2) ... 
	int N; cin >> N;
	cout << t(N) << endl;
	return 0;
}

