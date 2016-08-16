#include <iostream>
#include <cmath>
using namespace std;
int main() {
	// sqrt(N)

	long long N, K; cin >> N >> K;

	long long result = 0;
	// K % N ~ K % (K + 1)
	if (N > K) result += (N - K) * K;

