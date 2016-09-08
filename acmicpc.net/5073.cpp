#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c == 0) break;

		int total = a + b + c;
		int lg = max(a, max(b, c));
		if (total - lg <= lg) {
			cout << "Invalid" << endl;
		} else {
			if (a == b && b == c) {
				cout << "Equilateral" << endl;
			} else if (a != b && b != c && a != c) {
				cout << "Scalene" << endl;
			} else {
				cout << "Isosceles" << endl;
			}
		}
	}
	return 0;
}
