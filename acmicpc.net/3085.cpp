#include <iostream>
#include <queue>
using namespace std;
enum { U, D, L, R };
struct point {
	int x, y, d, k, c;
	char candy;
};
char M[51][51];
int AX[4] = { 0, 0, -1, 1 }, AY[4] = { -1, 1, 0, 0 };
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> M[i][j];

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int count = 0;
				int nx = j;
				int ny = i;
				char ncandy = M[ny][nx];
				char candy = M[i][j];
				while (ncandy == candy) {
					nx += AX[k];
					ny += AY[k];
					ncandy = M[ny][nx];
					count++;
				}

				// 1È¸ ±³Ã¼
				if (k == U || k == D) {
					if (M[ny][nx + 1] == candy || M[ny][nx - 1] == candy) {
						ncandy = candy;
						while (ncandy == candy) {
							nx += AX[k];
							ny += AY[k];
							ncandy = M[ny][nx];
							count++;
						}
					}
				} else if (k == L || k == R) {
					if (M[ny + 1][nx] == candy || M[ny - 1][nx] == candy) {
						ncandy = candy;
						while (ncandy == candy) {
							nx += AX[k];
							ny += AY[k];
							ncandy = M[ny][nx];
							count++;
						}
					}
				}
				result = max(result, count);
			}
		}
	}
	cout << result << endl;
	return 0;
}
 