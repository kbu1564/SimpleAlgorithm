#include <iostream>
using namespace std;
int C[7];
int main() {
	for (int i = 1; i <= 6; i++) cin >> C[i];

	int result = C[6];

	if (C[5] > 0) {
		result += C[5];
		C[1] -= C[5] * 11;
	}

	if (C[4] > 0) {
		result += C[4];
		if (C[2] > 0) {
			C[2] -= C[4] * 5;
		} else {
			C[1] -= C[4] * 20;
		}
	}

	if (C[3] > 0) {
		result += C[3] / 4 + (C[3] % 4 > 0);
		if (C[3] % 4 == 3) {
			if (C[2] > 0) {
				C[2] -= 1;
				C[1] -= 5;
			} else {
				C[1] -= 9;
			}
		} else if (C[3] % 4 == 2) {
			if (C[2] > 0) {
				C[2] -= 3;
				C[1] -= 6;
			} else {
				C[1] -= 18;
			}
		} else if (C[3] % 4 == 1) {
			if (C[2] > 0) {
				C[2] -= 5;
				C[1] -= 7;
			} else {
				C[1] -= 27;
			}
		}
	}

	if (C[2] > 0) {
		result += C[2] /9 + (C[2] % 9 > 0);
		if (C[2] % 9 > 0) {
			C[1] -= 36 - (C[2] % 9 * 4);
		}
	}

	if (C[1] > 0) {
		result += C[1] / 36 + (C[1] % 36 > 0);
	}

	cout << result << endl;

	return 0;
}
