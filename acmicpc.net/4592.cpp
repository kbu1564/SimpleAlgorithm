#include <iostream>
using namespace std;

int main() {
	while (1) {
		int ARR[100] = { 0, };
		int N; cin >> N;
		if (N == 0) break;

		int old = 0;
		for (int i = 0; i < N; i++) {
			int ni; cin >> ni;
			if (old != ni) {
				cout << ni << " ";
			}
			old = ni;
		}
		cout << "$" << endl;
	}
	return 0;
}
