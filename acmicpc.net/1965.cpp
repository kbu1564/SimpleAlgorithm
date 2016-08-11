#include <iostream>
#include <algorithm>
using namespace std;
int DP[1001], ARR[1001];
int main() {
	int N; cin >> N;
	// 1개만 들어 왔을 때에도 허용되야 하므로
	for (int i = 1; i <= N; i++) {
		cin >> ARR[i];
		for (int j = 0; j < i; j++) {
			if (ARR[i] > ARR[j] && DP[i] < DP[j] + 1) {
				DP[i] = DP[j] + 1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 1001; i++) result = max(result, DP[i]);
	cout << result << endl;
	return 0;
}