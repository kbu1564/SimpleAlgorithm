#include <iostream>
using namespace std;

struct item {
	int r, g;
};

int N, L;
item D[1001];
int main() {
	cin >> N >> L;

	int d = 0;
	int curr = 0;
	int result = 0;
	for (int i = 0; i < N; i++) {
		cin >> d;
		cin >> D[d].r >> D[d].g;
		result += d - curr;
		curr = d;

		int wait = result % (D[d].r + D[d].g);
		if (wait < D[d].r) {
			result += D[d].r - wait;
		}
	}
	if (d < L) result += L - d;

	cout << result << endl;
	return 0;
}
