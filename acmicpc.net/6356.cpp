#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
enum { EAST = 0, SOUTH, WEST, NORTH };
struct point {
	int x, y, dist;
	int turn, go;
};
const int AX[4] = { 1, 0, -1, 0 }, AY[4] = { 0, 1, 0, -1 };
int main() {
	int N, M;
	for (;;) {
		int MAP[52][52] = { 0, };
		int VIS[52][52][4] = { 0, };

		cin >> N >> M;
		if (N == 0 && M == 0) break;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> MAP[i][j];

		for (int i = 0; i < 52; i++) {
			for (int j = 0; j < 52; j++) {
				VIS[i][j][EAST] = VIS[i][j][SOUTH] = 1e9;
				VIS[i][j][WEST] = VIS[i][j][NORTH] = 1e9;
			}
		}

		int SX, SY, EX, EY;
		cin >> SY >> SX >> EY >> EX;

		string DIST;
		cin >> DIST;

		int dist = -1;
		if (DIST == "west")  dist = WEST;
		if (DIST == "east")  dist = EAST;
		if (DIST == "south") dist = SOUTH;
		if (DIST == "north") dist = NORTH;

		queue<point> Q;
		Q.push({ SX, SY, dist });
		while (!Q.empty()) {
			point data = Q.front(); Q.pop();
			if (data.x < 1 || data.y < 1 || data.x >= M || data.y >= N) continue;
			// 이동시 왼쪽, 위, 왼쪽위(대각)에 장애물에 없어야함
			int check = MAP[data.y][data.x] + MAP[data.y-1][data.x] + MAP[data.y][data.x-1] + MAP[data.y-1][data.x-1];
			if (check > 0) continue;

			if (VIS[data.y][data.x][data.dist] <= data.turn + data.go) continue;
			VIS[data.y][data.x][data.dist] = data.turn + data.go;

			if (data.x == EX && data.y == EY) continue;

			// GO 명령은 1초에 1, 2, 3m 를 이동 가능
			int nx = data.x;
			int ny = data.y;
			for (int j = 1; j <= 3; j++) {
				nx += AX[data.dist];
				ny += AY[data.dist];

				// 갈 수 있는 곳인지 체크
				if (nx > 0 && ny > 0 && nx < M && ny < N) {
					check = MAP[ny][nx] + MAP[ny-1][nx] + MAP[ny][nx-1] + MAP[ny-1][nx-1];
					if (check > 0) break;
				} else break;

				Q.push({ nx, ny, data.dist, data.turn, data.go + 1 });
			}

			// TURN 명령 처리 왼쪽, 오른쪽
			Q.push({ data.x, data.y, (data.dist + 1) % 4, data.turn + 1, data.go });
			Q.push({ data.x, data.y, (data.dist + 3) % 4, data.turn + 1, data.go });
		}

		int result = 1e9;
		for (int i = 0; i < 3; i++) result = min(result, VIS[EY][EX][i]);

		cout << (result >= 1e9? -1: result) << endl;
	}
	return 0;
}
