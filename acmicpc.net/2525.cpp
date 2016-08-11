#include <iostream>
using namespace std;
int main() {
	int a, b; cin >> a >> b;
	int c; cin >> c;

	b += c;
	a = (a + b / 60) % 24;
	b %= 60;

	cout << a << " " << b << endl;
	return 0;
}