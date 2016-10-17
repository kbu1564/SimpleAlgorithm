#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		unsigned long long x, y; cin >> x >> y;
		unsigned long long cx = 1, cy = 1, curr = 0;

		curr = y;
		while (curr / 2 > 0) {
			cy += curr; curr /= 2;
		}

		curr = x;
		while (curr / 2 > 0) {
			cx += curr; curr /= 2;
		}

		unsigned long long result = cy - cx;
		cout << result << endl;
	}
	return 0;
}

