#include <iostream>
#include <algorithm>
using namespace std;
int ARR[1001], DP[1001];
int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ARR[i];
		for (int j = 0; j < i; j++) {
			if (ARR[i] > ARR[j]) {
				DP[i] = max(DP[i], DP[j] + ARR[i]);
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 1001; i++) result = max(result, DP[i]);
	cout << result << endl;
	return 0;
}
