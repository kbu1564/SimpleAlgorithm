#include <iostream>
using namespace std;
int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int p, c; cin >> c >> p;
		cout << "You get " << (p == 0? 0: c / p) << " piece(s) and your dad gets " << (p == 0? 0: c % p) << " piece(s)." << endl;
	}
	return 0;
}
