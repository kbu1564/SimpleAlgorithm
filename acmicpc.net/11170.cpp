#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000001] = { 1, };
int main() {
	for (int i = 1; i < 1000001; i++) {
		int cnt = 0;
		int c = i;
		while (c > 0) {
			if (c % 10 == 0) cnt++;
			c /= 10;
		}
		DP[i] += DP[i-1] + cnt;
	}

	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int s, e; cin >> s >> e;

		int result = DP[e] - (s-1 < 0? 0: DP[s-1]);
		cout << result << endl;
	}
	return 0;
}
