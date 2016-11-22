#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
int K;
int MAP[1001][1001];
int VX[1001], VY[1001];
int DIST[4];
pair<int, int> solve(int sr, int sc) {
	pair<int, int> result = pair<int, int>(sr, sc);
	int nextDist = 0;
	while (1) {
		// 1 : 상, 2 : 하, 3 : 좌, 4 : 우
		while (MAP[result.first][result.second] == 0) {
			int br = result.first;
			int bc = result.second;

			if (DIST[nextDist] == 1) br--;
			if (DIST[nextDist] == 2) br++;
			if (DIST[nextDist] == 3) bc--;
			if (DIST[nextDist] == 4) bc++;

			if (MAP[br][bc] == 1) break;
			if (br < 0 || br > R-1) break;
			if (bc < 0 || bc > C-1) break;

			MAP[result.first][result.second] = 1;
			result.first = br;
			result.second = bc;
		}
		nextDist = (nextDist + 1) % 4;

		int check = 0;
		if (result.first-1 < 0 || MAP[result.first-1][result.second] == 1) check++;
		if (result.first+1 > R-1 || MAP[result.first+1][result.second] == 1) check++;
		if (result.second-1 < 0 || MAP[result.first][result.second-1] == 1) check++;
		if (result.second+1 > C-1 || MAP[result.first][result.second+1] == 1) check++;
		if (check == 4) break;
		cout << check << " : " << result.first << " " << result.second << " (" << nextDist << ")" << endl;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) cout << MAP[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	return result;
}
int main() {
	scanf("%d %d", &R, &C);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int br, bc;
		scanf("%d %d", &br, &bc);
		MAP[br][bc] = 1;
	}
	int SR, SC;
	scanf("%d %d", &SR, &SC);
	for (int i = 0; i < 4; i++) {
		scanf("%d", &DIST[i]);
	}

	pair<int, int> result = solve(SR, SC);
	printf("%d %d\n", result.first, result.second);
	return 0;
}
