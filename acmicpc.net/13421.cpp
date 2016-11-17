#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int X[4], Y[4];
int main() {
	for (int i = 0; i < 4; i++) cin >> X[i] >> Y[i];

	int s = 1;
	int e = 1e9;
	int ans = 0;
	long long result = 1e9 * 4;
	while (s + 1 < e) {
		int m = (s + e) / 2;
		long long dist = 0;
		for (int i = 0; i < 4; i++) {
			dist += abs(m - abs(X[i])) + abs(m - abs(Y[i]));
		}
		//cout << m << " = " << dist << endl;
		if (result < dist) {
			s = m;
		} else {
			e = m;
			result = dist;
			ans = m;
		}
	}
	while (1) {
		int dist = 0;
		for (int i = 0; i < 4; i++) {
			dist += abs(ans + 1 - abs(X[i])) + abs(ans + 1 - abs(Y[i]));
		}
		//cout << ans << " = " << dist << endl;
		if (result < dist) {
			break;
		} else {
			ans++;
			result = dist;
		}
	}
	cout << 2 * ans << endl;
	return 0;
}

