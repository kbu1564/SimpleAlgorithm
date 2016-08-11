#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct point {
	int x, y, k, step;
};
const int SIZE = 1500001;
point Q[SIZE];
int AX[12] = { 1, -1, 0, 0, -2, -1, 1, 2, -2, -1, 2, 1 };
int AY[12] = { 0, 0, 1, -1, -1, -2, -2, -1, 1, 2, 1, 2 };
int f, r;
int VISIT[201][201], KVISIT[201][201], MAP[201][201];
int main() {
	for (int i = 0; i < 201; i++) for (int j = 0; j < 201; j++) VISIT[i][j] = 1e9;

	int K; cin >> K;
	int W, H; cin >> W >> H;
	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> MAP[i][j];

	Q[r++] = (point){ 0, 0, K, 0 };
	r %= SIZE;
	while (f != r) {
		point& data = Q[f++];
		f %= SIZE;

		if (data.k < 0) continue;
		if (data.x < 0 || data.y < 0 || data.x >= W || data.y >= H) continue;
		if (MAP[data.y][data.x] == 1) continue;
		if (data.step >= VISIT[data.y][data.x] && data.k <= KVISIT[data.y][data.x]) continue;
		VISIT[data.y][data.x] = data.step;
		KVISIT[data.y][data.x] = data.k;

		for (int i = 0; i < 12; i++) {
			int nx = data.x + AX[i];
			int ny = data.y + AY[i];
			if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
			if (data.k - (i > 3) < 0) continue;
			if (MAP[ny][nx] == 1) continue;
			if (VISIT[ny][nx] <= data.step + 1 && KVISIT[ny][nx] >= data.k - (i > 3)) continue;
			Q[r++] = (point){ nx, ny, data.k - (i > 3), data.step + 1 };
			r %= SIZE;
		}
	}

	cout << (VISIT[H-1][W-1] >= 1e9? -1: VISIT[H-1][W-1]) << endl;
	return 0;
}

