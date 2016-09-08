#include <iostream>
using namespace std;
int main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	int t = a + b + c + d;
	cout << t / 60 << endl;
	cout << t % 60 << endl;
	return 0;
}
