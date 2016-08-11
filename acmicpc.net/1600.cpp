#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct point {
	int x, y, k, step;
};
int AX[12] = { 1, -1, 0, 0, -2, -1, 1, 2, -2, -1, 2, 1 };
int AY[12] = { 0, 0, 1, -1, -1, -2, -2, -1, 1, 2, 1, 2 };
int VISIT[201][201];
int MAP[201][201];
int main() {
	int K; cin >> K;
	int W, H; cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> MAP[i][j];
			VISIT[i][j] = -1;
		}
	}

	int result = 1e9;
	queue<point> Q;
	Q.push({ 0, 0, K, 0 });
	while (!Q.empty()) {
		point data = Q.front(); Q.pop();

		if (data.k < 0) continue;
		if (data.x < 0 || data.y < 0 || data.x >= W || data.y >= H) continue;
		if (MAP[data.y][data.x] == 1) continue;
		if (data.x >= W-1 && data.y >= H-1)
			result = min(result, data.step);

		if (VISIT[data.y][data.x] >= data.k) continue;
		VISIT[data.y][data.x] = data.k;

		for (int i = 0; i < 12; i++) {
			int nx = data.x + AX[i];
			int ny = data.y + AY[i];
			int nk = data.k - (i > 3);
			Q.push({ nx, ny, nk, data.step + 1 });
		}
	}

	cout << (result >= 1e9? -1: result) << endl;
	return 0;
}
