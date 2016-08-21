#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int MAP[101][101];
int main() {
	vector< pair<int, int> > v;
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int r, c; cin >> r >> c;
		MAP[c][r]++;
	}

	int moveCount = 1e9;
	int minNeedCount = 1e9;
	for (int i = 1; i * i <= M && i <= N; i++) {
		if (M % i == 0 && M/i <= N) {
			for (int y = 1; y <= N; y++) {
				for (int x = 1; x <= N; x++) {
					pair<int, int> p = pair<int, int>(x, y);

					int lx[2] = { M/i, i };
					int ly[2] = { i, M/i };

					for (int k = 0; k < 2; k++) {
						int unmoveCount = 0;
						int needCount = 0;
						if (p.first + lx[k] - 1 <= N && p.second + ly[k] - 1 <= N) {
							for (int h = 0; h < ly[k]; h++) for (int w = 0; w < lx[k]; w++) {
								if (MAP[p.second + h][p.first + w] == 0) needCount++;
								if (MAP[p.second + h][p.first + w] >= 1) unmoveCount++;
							}

							if (minNeedCount > needCount && needCount == M - unmoveCount) {
								moveCount = M - unmoveCount;
								minNeedCount = needCount;
							}
						}
					}
				}
			}
		}
	}

	cout << (minNeedCount >= 1e9? 0: minNeedCount) << endl;
	return 0;
}
