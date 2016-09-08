#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

inline int _max(int a, int b) { return a > b? a: b; }
inline int _min(int a, int b) { return a > b? b: a; }

const int SIZE = 200001;
int N;
int MAP[101][101];
int QX[SIZE], QY[SIZE], QMIN[SIZE], QMAX[SIZE];
int AX[4] = { -1, 1, 0, 0 }, AY[4] = { 0, 0, -1, 1 };
int DP[101][101];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) scanf("%d", &MAP[i][j]);

	int low = 0, hight = 201;
	while (low < hight) {
		for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) DP[i][j] = 1e9;

		int mid = (low + hight) / 2;
		int f = 0, r = 0;
		QX[r] = 1, QY[r] = 1, QMIN[r] = MAP[1][1], QMAX[r] = MAP[1][1];
		r = (r + 1) % SIZE;
		while (f < r) {
			int x = QX[f], y = QY[f];
			int deltaMin = QMIN[f], deltaMax = QMAX[f];
			f = (f + 1) % SIZE;
			
			if (x < 1 || y < 1 || x > N || y > N) continue;

			deltaMin = _min(deltaMin, MAP[y][x]);
			deltaMax = _max(deltaMax, MAP[y][x]);
			if (deltaMax - deltaMin > mid) continue;
			if (DP[y][x] <= deltaMax - deltaMin) continue;
			DP[y][x] = deltaMax - deltaMin;

			if (x == N && y == N) break;

			for (int k = 0; k < 4; k++) {
				int nx = x + AX[k], ny = y + AY[k];
				QX[r] = nx; QY[r] = ny;
				QMIN[r] = deltaMin; QMAX[r] = deltaMax;
				r = (r + 1) % SIZE;
			}
		}

		//cout << mid << " : " << "Arrived(" << DP[N][N] << ")" << endl;
		//cout << low << " ~ " << hight << endl;
		if (DP[N][N] < 1e9) hight = mid;
		else low = mid + 1;
		//cout << low << " ~ " << hight << endl << endl;
	}
	printf("%d\n", hight);
	return 0;
}
