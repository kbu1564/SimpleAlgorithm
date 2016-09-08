#include <iostream>
#include <algorithm>
using namespace std;

int DP[201];
int ARR[201];
int main() {
	int result = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ARR[i];

		for (int j = 0; j <= i; j++) {
			if (ARR[j] < ARR[i] && DP[i] < DP[j] + 1) {
				DP[i] = DP[j] + 1;
			}
		}
		result = max(result, DP[i]+1);
	}
	cout << N - result << endl;
	return 0;
}
