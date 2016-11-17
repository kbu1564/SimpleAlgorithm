#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int N; cin >> N;

	int t2 = 0, t5 = 0;
	for (int i = 1; i <= N; i++) {
		int cnt2 = 0, cnt5 = 0;
		int tmp2 = i, tmp5 = i;
		while (tmp2 % 2 == 0) {
			cnt2++; tmp2 /= 2;
		}
		while (tmp5 % 5 == 0) {
			cnt5++; tmp5 /= 5;
		}
		t2 += cnt2; t5 += cnt5;
	}

	cout << min(t2, t5) << endl;
	return 0;
}
