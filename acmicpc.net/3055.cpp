#include <iostream>
#include <queue>
using namespace std;

struct item {
	int x, y, t;
};
char MAP[51][51];
int VIS[51][51];
int WAT[51][51];
int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
int main() {
	queue<item> GQ;
	queue<item> WQ;
	int R, C; cin >> R >> C;
	for (int i = 0; i < 51; i++) for (int j = 0; j < 51; j++) VIS[i][j] = WAT[i][j] = 1e9;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'S') {
				GQ.push({ j, i, 0 });
			}
			if (MAP[i][j] == '*') {
				WQ.push({ j, i, 0 });
			}
		}
	}

	// 물
	while (!WQ.empty()) {
		item data = WQ.front(); WQ.pop();
		if (data.x < 0 || data.y < 0 || data.x >= C || data.y >= R) continue;
		if (MAP[data.y][data.x] == 'X') continue;
		if (MAP[data.y][data.x] == 'D') continue;
		if (WAT[data.y][data.x] < 1e9) continue;
		WAT[data.y][data.x] = data.t;

		for (int i = 0; i < 4; i++) {
			int nx = data.x + AX[i];
			int ny = data.y + AY[i];
			WQ.push({ nx, ny, data.t + 1 });
		}
	}

	// 길찾기
	int result = 1e9;
	while (!GQ.empty()) {
		item data = GQ.front(); GQ.pop();
		if (data.x < 0 || data.y < 0 || data.x >= C || data.y >= R) continue;
		if (MAP[data.y][data.x] == 'X') continue;
		if (WAT[data.y][data.x] <= data.t) continue;
		if (VIS[data.y][data.x] <= data.t) continue;
		if (MAP[data.y][data.x] == 'D') {
			result = data.t;
			break;
		}
		VIS[data.y][data.x] = data.t;

		for (int i = 0; i < 4; i++) {
			int nx = data.x + AX[i];
			int ny = data.y + AY[i];
			GQ.push({ nx, ny, data.t + 1 });
		}
	}
	if (result >= 1e9) cout << "KAKTUS" << endl;
	else cout << result << endl;
	return 0;
}
