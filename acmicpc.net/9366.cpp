#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int a, b, c; cin >> a >> b >> c;
		int mx = max(a, max(b, c));
		int mi = min(a, min(b, c));
		b = a + b + c - mx - mi;
		a = mi;
		c = mx;

		cout << "Case " << tc << ": ";
		if (a + b <= c) cout << "invalid!" << endl;
		else if (a == b && b == c) cout << "equilateral" << endl;
		else if (a != b && b != c && a != c) cout << "scalene" << endl;
		else cout << "isosceles" << endl;
	}
	return 0;
}
