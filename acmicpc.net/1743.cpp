#include <iostream>
#include <queue>
using namespace std;

struct node { int x, y; };

int AX[4] = { 0, 0, 1, -1 };
int AY[4] = { 1, -1, 0, 0 };

int MAP[101][101];
int main() {
	ios::sync_with_stdio(false);
	int N, M, K; cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int y, x; cin >> y >> x;
		MAP[y][x] = 1;
	}

	int result = 0;
	int VIS[101][101] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (VIS[i][j] == 1 || MAP[i][j] == 0) continue;
			int count = 0;
			queue<node> Q;
			Q.push({ j, i });
			while (!Q.empty()) {
				node data = Q.front(); Q.pop();
				if (data.x < 1 || data.y < 1 || data.x > M || data.y > N) continue;
				if (MAP[data.y][data.x] == 0) continue;
				if (VIS[data.y][data.x] == 1) continue;
				VIS[data.y][data.x] = 1;
				count++;
				for (int k = 0; k < 4; k++) {
					int nx = data.x + AX[k];
					int ny = data.y + AY[k];
					Q.push({ nx, ny });
				}
			}
			result = max(result, count);
		}
	}

	cout << result << endl;
	return 0;
}
