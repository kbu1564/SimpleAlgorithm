#include <iostream>
using namespace std;
int main() {
	int N; cin >> N;
	int U1, U2; cin >> U1 >> U2;

	int curr = 1;
	int rnd = 0;
	int u1r = 0, u2r = 0;
	do {
		int j = 1;
		curr *= 2;
		for (int i = 1; i <= N; i+=curr, j++) {
			for (int k = i; k <= N && k < i+curr; k++) {
				if (k == U1) u1r = j;
				if (k == U2) u2r = j;
			}
		}
		rnd++;
	} while (u1r != u2r);
	cout << rnd << endl;
	return 0;
}

