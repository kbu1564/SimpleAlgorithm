#include <iostream>
#include <vector>
using namespace std;
int MM[9][9][10];
int M[9][9];
int main() {
	int zero = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> M[i][j];
			if (M[i][j] == 0) {
				zero++;
			}
		}
	}

	while (zero > 0) {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				for (int k = 1; k < 10; k++)
					MM[i][j][k] = 0;

		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				int x, y;
				int C = 45;
				int zeroCount = 0;
				for (int ii = i; ii < i + 3; ii++) {
					for (int jj = j; jj < j + 3; jj++) {
						C -= M[ii][jj];
						if (M[ii][jj] == 0) {
							zeroCount++;
							x = jj; y = ii;
						}
					}
				}

				if (zeroCount == 1) {
					zero--;
					M[y][x] = C;
				}
			}
		}

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (M[i][j] == 0) {
					int CK[10] = { 0, };
					for (int k = 0; k < 10; k++) CK[k] = 0;
					for (int k = 0; k < 9; k++) CK[M[i][k]]++;
					for (int k = 1; k < 10; k++) {
						if (CK[k] == 0) MM[i][j][k]++;
					}

					for (int k = 0; k < 10; k++) CK[k] = 0;
					for (int k = 0; k < 9; k++) CK[M[k][j]]++;
					for (int k = 1; k < 10; k++) {
						if (CK[k] == 0) MM[i][j][k]++;
					}

					for (int k = 1; k < 10; k++) {
						if (M[i][j] == 0 && MM[i][j][k] > 1) {
							zero--;
							M[i][j] = k;
						}
						MM[i][j][k] = 0;
					}
				}
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
