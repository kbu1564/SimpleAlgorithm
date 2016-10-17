#include <iostream>
using namespace std;

int main() {
	int N, L; cin >> N >> L;

	// L*x + (L^2 - L) / 2 = N
	while (L <= 100) {
		// x = (N - (L*L - L) / 2) / L;
		if ((N - (L*L - L) / 2) % L == 0) break;
		L++;
	}

	int xL = (N - (L*L - L) / 2);
	if (xL % L == 0 && L <= 100) {
		int x = xL / L;
		if (x < 0) {
			cout << -1;
		} else {
			for (int i = 0; i < L; i++) cout << x + i << " ";
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}

