#include <iostream>
using namespace std;

int SIZE = 5000;
int N, M;
int VIS[51][51];
char MAP[51][51];
pair<int, int> Q[SIZE];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> MAP[i][j];
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		if (VIS[i][j]) continue;
		int f = 0, r = 0;
		Q[r=(r+1)%SIZE] = pair<int, int>(j, i);
		while (f != j) {
			pair<int, int> data = Q[f=(f+1)%SIZE];
			if (data.first < 0 || data.second < 0 || data.first >= M || data.second >= N) continue;
			if (MAP[data.second][data.first] != 'L') continue;
			if (VIS[data.second][data.first]) continue;
			VIS[data.second][data.first] = 1;
			// ???
			//if (data.first == 

			int AX[4] = { -1, 1, 0, 0 }, AY[4] = { 0, 0, -1, 1 };
			for (int k = 0; k < 4; k++) {
				int nx = data.first + AX[k];
				int ny = data.second + AY[k];
				Q[r=(r+1)%SIZE] = pair<int, int>(nx, ny);
			}
		}
	}
	return 0;
}
