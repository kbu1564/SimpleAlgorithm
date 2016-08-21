#include <iostream>
#include <cmath>
using namespace std;

long long DP[1000001];
int main() {
	long long N1, N2;
	cin >> N1 >> N2;

	long long result = 0;
	for (long long i = N1; i <= N2; i++) {
		result++;
		for (long long j = 2; j * j <= N2; j++) {
			if (i % (j*j) == 0) {
				result--; break;
			}
		}
	}
	cout << result << endl;
	return 0;
}

