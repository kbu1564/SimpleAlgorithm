#include <iostream>
using namespace std;

struct mm { int x, y; };
const int SIZE = 50000;
mm Q[SIZE];
char M[101][101];
int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> M[i][j];

	int cntN = 0;
	int V2[101][101] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (V2[i][j] == 1) continue;
			// RG
			int f = 0, r = 0;
			char V = M[i][j];
			Q[r++] = { j, i };
			r = r % SIZE;
			while (f < r) {
				mm data = Q[f++];
				f = f % SIZE;
				if (data.x < 0 || data.x >= N || data.y < 0 || data.y >= N) continue;
				V2[data.y][data.x] = 1;
				for (int k = 0; k < 4; k++) {
					int nx = data.x + AX[k];
					int ny = data.y + AY[k];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (V2[ny][nx] == 1) continue;
					if (V == M[ny][nx]) {
						Q[r++] = { nx, ny };
						r = r % SIZE;
					}
				}
			}
			cntN++;
		}
	}
	cout << cntN << " ";

	int cntRG = 0;
	int V1[101][101] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (V1[i][j] == 1) continue;
			// RG
			int f = 0, r = 0;
			char V = M[i][j];
			Q[r++] = { j, i };
			r = r % SIZE;
			while (f < r) {
				mm data = Q[f++];
				f = f % SIZE;
				if (data.x < 0 || data.x >= N || data.y < 0 || data.y >= N) continue;
				V1[data.y][data.x] = 1;
				for (int k = 0; k < 4; k++) {
					int nx = data.x + AX[k];
					int ny = data.y + AY[k];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (V1[ny][nx] == 1) continue;
					if ((V == 'R' || V == 'G') && (M[ny][nx] == 'R' || M[ny][nx] == 'G')) {
						Q[r++] = { nx, ny };
						r = r % SIZE;
					} else if (V == 'B' && M[ny][nx] == 'B') {
						Q[r++] = { nx, ny };
						r = r % SIZE;
					}
				}
			}
			cntRG++;
		}
	}
	cout << cntRG << endl;
	return 0;
}

