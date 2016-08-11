#include <iostream>
#include <queue>
using namespace std;

const int Width = 6;
const int Height = 12;
int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
char MAP[Height + 1][Width + 1];
char MAP_TEMP[Height + 1][Width + 1];

struct block {
	int x, y;
	char v;
};
int main() {
	int totalBlockCount = 0;
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			cin >> MAP[i][j];
			MAP_TEMP[i][j] = MAP[i][j];
			if (MAP[i][j] != '.') totalBlockCount++;
		}
	}

	int result = 0;
	int nextTotalBlockCount = 0;
	int REMOVEW[Width + 1] = { 0, };
	int REMOVEH[Height + 1] = { 0, };
	while (totalBlockCount > 0 && nextTotalBlockCount != totalBlockCount) {
		nextTotalBlockCount = totalBlockCount;

		int VISIT[Height + 1][Width + 1] = { 0, };
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				if (VISIT[i][j]) continue;
				if (MAP[i][j] == '.') continue;

				int tmpWidth[Width + 1] = { 0, };
				int tmpHeight[Height + 1] = { 0, };
				int REMOVE[Height + 1][Width + 1] = { 0, };
				// 부수기 위한 뿌요뿌요 블록
				char thisBlock = MAP[i][j];
				int blockCount = 0;
				queue<block> Q;
				Q.push({ j, i, MAP[i][j] });
				while (!Q.empty()) {
					block data = Q.front(); Q.pop();
					if (data.v == '.' || data.v != thisBlock) continue;
					VISIT[data.y][data.x] = 1;
					REMOVE[data.y][data.x] = 1;
					blockCount++;

					for (int k = 0; k < 4; k++) {
						int nx = data.x + AX[k];
						int ny = data.y + AY[k];
						if (nx < 0 || ny < 0 || nx >= Width || ny >= Height) continue;
						if (MAP[ny][nx] != thisBlock) continue;
						if (VISIT[ny][nx]) continue;
						Q.push({ nx, ny, MAP[ny][nx] });
					}
				}

				if (blockCount >= 4) {
					// 뿌요뿌요 블럭 부수기
					for (int y = 0; y < Height; y++) {
						for (int x = 0; x < Width; x++) {
							if (REMOVE[y][x] == 1) {
								MAP[y][x] = MAP_TEMP[y][x] = '.';
								totalBlockCount--;
							}
						}
					}

					int TAKEX[Width + 1] = { 0, };
					// x 축 자체가 제거됬는지 확인
					for (int x = 0; x < Width; x++) {
						// 해당 라인이 지워졌는지 체크
						TAKEX[x] = 1;
						for (int y = Height - 1; y >= 0; y--) {
							if (MAP[y][x] != '.') {
								TAKEX[x] = 0;
								break;
							}
						}
					}

					// 제거된 블록 당기기
					int beforeTakeX = 0;
					for (int x = 0; x < Width; x++) {
						if (TAKEX[x] == 0) {
							int s = Height - 1;
							int e = 0;
							for (int y = Height - 1; y >= 0; y--) {
								if (REMOVE[y][x] == 1) {
									if (y < s) s = y;
									if (y > e) e = y;
								}
							}
							int deleteCount = e - s + 1;
							for (int y = 0; y <= s; y++) {
								MAP[y + deleteCount][x] = MAP_TEMP[y][x];
								MAP[y][x] = '.';
							}
						} else {
						}
					}
				}
			}
		}

		for (int y = 0; y < Height; y++) {
			for (int x = 0; x < Width; x++) {
				//MAP[y][x] = MAP_TEMP[y][x];
				cout << MAP_TEMP[y][x];
			}
			cout << endl;
		}
		cout << endl << endl;
		result++;
	}
	cout << result << endl;
	return 0;
}