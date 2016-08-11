#include <iostream>
#include <queue>
using namespace std;
const char BLACK = '1';
const char WHITE = '0';
const int MAXROOM = 987654321;
const int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
const int AXY[][2] = {
	{ -1, -1 }, { 0, -1 }, { 1, -1 },
	{ -1, 0  }, { 0, 0  }, { 1, 0  },
	{ -1, 1  }, { 0, 1  }, { 1, 1  }
};
char M[51][51];
struct p { int x, y, c; };
queue<p> Q;
bool check(int x, int y, int N, int M) {
	return x >= 0 && x < N && y >= 0 && y < M;
}
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> M[i][j];

	// 탐욕법 : 우선순위 1 : 흰방, 2 : 방문하지 않은 흰방, 우선순위 3 : 검은방 -> 흰방
	int result = MAXROOM;
	int VISIT[51][51] = { 1, };
	p pp = { 0, };
	Q.push(pp);
	while (!Q.empty()) {
		p data = Q.front(); Q.pop();
		if (!check(data.x, data.y, N, N)) continue;
		if (data.x == N-1 && data.y == N-1) {
			result = min(result, data.c);
			continue;
		}
		VISIT[data.y][data.x] = 1;
		int Qsize = Q.size();
		for (int i = 0; i < 4; i++) {
			int nx = data.x + AX[i];
			int ny = data.y + AY[i];
			if (!check(nx, ny, N, N)) continue;
			if (VISIT[ny][nx] == 1) continue;
			if (M[ny][nx] == WHITE) {
				// 이동이 가능하다면 우선 이동
				VISIT[ny][nx] = 1;
				p tmp = { nx, ny, data.c };
				Q.push(tmp);
			}
		}
		if (Qsize == Q.size()) {
			// 더이상 방문한 것들 중 흰방이 존재하지 않은 경우
			// 대각선 방향으로 흰방이 존재하는지 검사
			for (int i = 0; i < 9; i++) {
				int nx = data.x + AXY[0][i];
				int ny = data.y + AXY[1][i];
				if (nx == data.x && ny == data.y) continue;
				if (VISIT[ny][nx] == 1) continue;
				if (M[ny][nx] == WHITE) {
					// 대각선 방향에 흰방이 보임
					// 검은방 1개 변경후 이동
					VISIT[ny][nx] = 1;
					p tmp = { nx, ny, data.c + 1 };
					Q.push(tmp);
				}
			}
		}
		if (Qsize == Q.size()) {
			// 대각선 방향에 흰방마저 존재하지 않음..
			// 이경우 그냥 모든 검은방을 흰방으로 취급하여 c + 1 하여 이동
			for (int i = 0; i < 4; i++) {
				int nx = data.x + AX[i];
				int ny = data.y + AY[i];
				if (nx == data.x && ny == data.y) continue;
				if (VISIT[ny][nx] == 1) continue;
				if (M[ny][nx] == BLACK) {
					// 검은방 1개 변경후 이동
					VISIT[ny][nx] = 1;
					p tmp = { nx, ny, data.c + 1 };
					Q.push(tmp);
				}
			}
		}
	}
	cout << result << endl;
	return 0;
}
