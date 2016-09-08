#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int mx = max(a, max(b, c));
	int mi = min(a, min(b, c));
	int t = a;
	b = a + b + c - mx - mi;
	a = mi;
	c = mx;

	int d = min(b - a, c - b);
	if (b - a != d) {
		cout << a + d << endl;
	} else if (c - b != d) {
		cout << b + d << endl;
	} else {
		int r1 = a - d;
		int r2 = c + d;
		cout << (r1 >= -100 && r1 <= 100? r1: r2) << endl;
	}

	return 0;
}
