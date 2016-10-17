#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int result;
int MAP[11][11], FILD[11][11];
int DX[11], DY[11];
int XN[11][11], YN[11][11];
pair<int, int> getDiagonal(int x, int y) {
	int tm = 0;
	int xn = 0, yn = 0;
	if (x == 0 || y == 0)
		return pair<int, int>(0, 0);
	if (x == 1 || y == 1 || x == N || y == N)
		return pair<int, int>(XN[y][x], YN[y][x]);

	tm = N - min(x, y);
	xn = XN[x + tm][y - tm];

	tm = N - max(x, y);
	yn = YN[x + tm][y + tm];

	return pair<int, int>(xn, yn);
}

void dfs(int x, int y, int c) {
	if (MAP[y][x] == 1) return;

	pair<int, int> p = getDiagonal(x, y);
	if (DX[p.first] == 1 || DY[p.second] == 1) return;

	MAP[y][x] = 1;
	DX[p.first] = DY[p.second] = 1;
	result = max(result, c);

	int tx = 0, ty = 0;
	if (y+1 <= N) {
		tx = 1; ty = y+1;
	} else {
		tx = x; ty = N;
		if (x > 1) {
			int tm = N - min(x, y);
			tx = x - tm;
		}
	}

	cout << x << ", " << y << " => " << tx << ", " << ty << endl;
	while (tx <= N && ty >= 1) {
		dfs(tx, ty, c+(tx > 0 && ty > 0 && FILD[ty][tx] == 1));
		tx++; ty--;
	}

	DX[p.first] = DY[p.second] = 0;
	MAP[y][x] = 0;
}

int main() {
	cin >> N;
	int n = 0;

	n = 1;
	for (int i = 1; i <= N; i++) XN[1][i] = XN[i][1] = n++;
	for (int i = 2; i <= N; i++) XN[i][N] = XN[N][i] = n++;
	n = 1;
	for (int i = N; i >= 2; i--) YN[i][1] = YN[N][N-i+1] = n++;
	for (int i = 1; i <= N; i++) YN[1][i] = YN[N-i+1][N] = n++;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> FILD[i][j];

	for (int i = 0; i <= N; i++) FILD[i][0] = FILD[0][i] = 1;
	dfs(0, 0, 0);

	cout << result << endl;
	return 0;
}

