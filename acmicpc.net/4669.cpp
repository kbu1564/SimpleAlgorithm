#include <iostream>
using namespace std;

const int SIZE = 1000;

int N, M, S;
inline bool getCheck(int x, int y) { return x > 0 && y > 0 && x <= M && y <= N; }
inline pair<int, int> getDist(char dist) {
	if (dist == 'N') return pair<int, int>(0, -1);
	if (dist == 'S') return pair<int, int>(0, 1);
	if (dist == 'E') return pair<int, int>(1, 0);
	return pair<int, int>(-1, 0);
}
int main() {
	while (1) {
		int VIS[11][11] = { 0, };
		char MAP[11][11] = { 0, };
		cin >> N >> M >> S;
		if (N + M + S == 0) break;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> MAP[i][j];
			}
		}

		int loopCount = 0;
		int outCount = 0;

		int QX[SIZE] = { 0, }; // x
		int QY[SIZE] = { 0, }; // y
		int QS[SIZE] = { 0, }; // step
		int f = 0, r = 0;
		QX[r] = S;
		QY[r] = 1;
		QS[r] = 1;
		r = (r+1)%SIZE;
		while (f != r) {
			int x = QX[f];
			int y = QY[f];
			char dist = MAP[y][x];
			int step = QS[f];
			f = (f+1)%SIZE;
			//cout << x << ", " << y << " = " << getCheck(x, y) << endl;
			if (!getCheck(x, y)) continue;
			if (VIS[y][x] > 0) {
				outCount = VIS[y][x];
				loopCount = step - VIS[y][x];
				break;
			}
			if (x == 1 && dist == 'W') {
				outCount = step + 1; break;
			}
			if (y == 1 && dist == 'N') {
				outCount = step + 1; break;
			}
			if (x == M && dist == 'E') {
				outCount = step + 1; break;
			}
			if (y == N && dist == 'S') {
				outCount = step + 1; break;
			}

			VIS[y][x] = step;

			pair<int, int> next = getDist(dist);
			int nx = x + next.first;
			int ny = y + next.second;
			if (!getCheck(nx, ny)) continue;

			QX[r] = nx;
			QY[r] = ny;
			QS[r] = step + 1;
			r = (r+1)%SIZE;
		}

		cout << outCount-1 << " step(s) ";
		if (loopCount-1 > 0) {
			cout << "before a loop of " << loopCount << " step(s)" << endl;
		} else {
			cout << "to exit" << endl;
		}
	}
	return 0;
}
