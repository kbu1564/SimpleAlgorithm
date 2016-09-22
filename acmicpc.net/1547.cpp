#include <iostream>
using namespace std;
int main() {
	int M; cin >> M;
	int ARR[4] = { 0, 1, 2, 3 };
	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;

		int t = ARR[x];
		ARR[x] = ARR[y];
		ARR[y] = t;
	}
	if (ARR[1] == 1) cout << 1 << endl;
	if (ARR[2] == 1) cout << 2 << endl;
	if (ARR[3] == 1) cout << 3 << endl;
	return 0;
}
