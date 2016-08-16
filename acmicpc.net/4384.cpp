#include <iostream>
#include <algorithm>
using namespace std;

int DP[50001];
int ARR[101];
int VIS[101];
int main() {
	int totalSum = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ARR[i];
		DP[ARR[i]] = 1;
		totalSum += ARR[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 50001; j++) {
			if (ARR[i] == j) continue;
			if (DP[j] == 1 && j + ARR[i] < 50001 && VIS[j + ARR[i]] == 0) {
				DP[j + ARR[i]] = 1;
				VIS[j + ARR[i]] = 0;
			}
		}
	}

	int result = 0;
	int half = totalSum / 2;
	for (int i = 0; i < 50001; i++) {
		if (DP[i] == 1 && abs(half - result) > abs(half - i)) {
			result = i;
		}
	}

	int rst1 = min(result, totalSum - result);
	int rst2 = max(result, totalSum - result);
	cout << rst1 << " " << rst2 << endl;
	return 0;
}
