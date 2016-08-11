#include <cmath>
#include <iostream>
using namespace std;
long long t, a, b, r;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		float sa = a, sb = b;
		long long rr = ceil(sa/sb);
		cout << rr*rr << endl;
	}
	return 0;
}

