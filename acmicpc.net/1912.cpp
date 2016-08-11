#include <iostream>
using namespace std;
int DP[100001];
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int ni; cin >> ni;
		if (i > 0) {
			if (DP[i-1] < 0)
				DP[i] = ni;
			else
				DP[i] = DP[i-1] + ni;
		} else {
			DP[i] = ni;
		}
	}

	int ans = DP[0];
	for (int i = 0; i < N; i++) ans = max(ans, DP[i]);

	cout << ans << endl;
	return 0;
}
