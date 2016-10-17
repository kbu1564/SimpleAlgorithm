#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct item {
	int x, y, h, c;
};

int AX[6] = { 0, 0, 0, 0, 1, -1 };
int AY[6] = { 0, 0, 1, -1, 0, 0 };
int AH[6] = { 1, -1, 0, 0, 0, 0 };

int M, N, H;
int TOMATO[101][101][101];
int main() {
	scanf("%d %d %d", &M, &N, &H);

	int noneCount = 0;

	queue<item> Q;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &TOMATO[k][i][j]);
				if (TOMATO[k][i][j] == 1) Q.push({ j, i, k, 0 });
				if (TOMATO[k][i][j] == 0) noneCount++;
			}
		}
	}

	int result = 0;
	while (!Q.empty()) {
		item data = Q.front(); Q.pop();
		if (TOMATO[data.h][data.y][data.x] != 1) continue;
		result = max(result, data.c);

		for (int k = 0; k < 6; k++) {
			int nx = data.x + AX[k];
			int ny = data.y + AY[k];
			int nh = data.h + AH[k];
			if (nx < 0 || ny < 0 || nh < 0 || nx >= M || ny >= N || nh >= H) continue;
			if (TOMATO[nh][ny][nx] == 0) {
				TOMATO[nh][ny][nx] = 1;
				Q.push({ nx, ny, nh, data.c + 1 });
				noneCount--;
			}
		}
	}

	printf("%d\n", noneCount == 0? result: -1);
	return 0;
}
