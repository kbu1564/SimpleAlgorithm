#include <iostream>
using namespace std;
int main() {
	int N; cin >> N;
	int two = 3;
	int thr = 5;
	int result = 0;
	for (int i = 4; i <= N; i++) {
		result = (two * 2 + thr) % 10007;
		two = thr;
		thr = result % 10007;
	}
	if (N == 1) cout << 1 << endl;
	if (N == 2) cout << 3 << endl;
	if (N == 3) cout << 5 << endl;
	if (N >= 4) cout << result << endl;
	return 0;
}
