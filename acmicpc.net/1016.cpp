#include <iostream>
#include <cmath>
using namespace std;
int DP[1000001] = { 1, };
int main() {
	long long N1, N2;
	cin >> N1 >> N2;

	for (int i = 1; i <= N2 - N1; i++) {
		if (i + N1 - 1 == 1) {
			DP[i] = 1;
			continue;
		}

		for (int j = 2; j <= 7; j++) {
			if (i + N1 - 1 == j) continue;
			if ((i + N1 - 1) % j == 0) {
				DP[i] = 1;
				break;
			}
		}
	}

	// 소수 개수 구하기
	int rst = 0;
	for (int i = 1; i <= N2 - N1; i++) {
		if (DP[i] == 0) {
			rst++;
		}
	}

	cout << rst << endl;
	return 0;
}
