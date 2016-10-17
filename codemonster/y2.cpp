#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct node {
	int x, y, c;
};

const int INF = 1e9;

int AX[4] = { 0, 0, 1, -1 }, AY[4] = { 1, -1, 0, 0 };

int T, R, C;
int PRIC[21];     // PRIC[i] = i 노드가 보물인 경우 가치
int NNUM[21][21]; // NNUM[i][j] = (j, i) 좌표가 노드인 경우의 번호
int GRAP[21][21]; // 1 : start, 2 ~ : 유물, GRAP[1][2] = 1 -> 2 까지의 최단 거리
int HRAP[21][21];
int DP[21][1<<20];
char MAP[21][21];

struct tsp {
	int v, total, price;
	int visit;
	inline void set(int n) {
		visit = visit | (1 << n);

		if (!this->get(n))
			price -= PRIC[n];
		else
			price += PRIC[n];
	}
	inline bool get(int n) { return visit & (1 << n); }
};

int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> R >> C;

		int idx = 2;
		pair<int, int> NODE[21] = { pair<int, int>(0, 0), };

		for (int i = 0; i < 21; i++) PRIC[i] = 0;
		for (int i = 0; i < 21; i++) for (int j = 0; j < (1 << 20); j++) DP[i][j] = INF;
		for (int i = 0; i < 21; i++) for (int j = 0; j < 21; j++) NNUM[i][j] = 0, GRAP[i][j] = INF, HRAP[i][j] = INF, MAP[i][j] = 0;
		for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];

			// node 기록
			if (MAP[i][j] == 'E') {
				NNUM[i][j] = 1;
				NODE[1] = pair<int, int>(j, i);
			} else if (MAP[i][j] != '~' && MAP[i][j] != '.') {
				PRIC[idx] = MAP[i][j] - '0';
				NNUM[i][j] = idx;
				NODE[idx] = pair<int, int>(j, i);
				idx++;
			}
		}

		// 그래프 생성
		for (int i = 1; i < idx; i++) {
			int weight = INF;
			int vis[21][21] = { 0, };
			queue<node> Q;
			Q.push({ NODE[i].first, NODE[i].second, 0 });
			while (!Q.empty()) {
				node data = Q.front(); Q.pop();
				if (data.x < 0 || data.y < 0 || data.x >= C || data.y >= R) continue;
				if (MAP[data.y][data.x] == '~') continue;
				if (vis[data.y][data.x] == 1) continue;

				vis[data.y][data.x] = 1;
				if (MAP[data.y][data.x] != '.' && i != NNUM[data.y][data.x]) {
					HRAP[i][NNUM[data.y][data.x]] = GRAP[i][NNUM[data.y][data.x]] = min(GRAP[i][NNUM[data.y][data.x]], data.c);
					continue;
				}

				for (int k = 0; k < 4; k++) {
					int nx = data.x + AX[k], ny = data.y + AY[k];
					if (MAP[ny][nx] == '~') continue;
					Q.push({ nx, ny, data.c + 1 });
				}
			}
		}

		for (int k = 1; k < idx; k++)
			for (int i = 1; i < idx; i++)
				for (int j = 1; j < idx; j++)
					if (HRAP[i][k] < INF && HRAP[k][j] < INF && HRAP[i][j] > HRAP[i][k] + HRAP[k][j])
						HRAP[i][j] = HRAP[i][k] + HRAP[k][j];

		// TSP
		/*
		cout << "1 -> 2 : " << GRAP[1][2] << endl;
		cout << "1 -> 3 : " << GRAP[1][3] << endl;
		cout << "2 -> 3 : " << GRAP[2][3] << endl;
		cout << endl;
		*/

		tsp debug = { 0, };
		int result = 0;
		stack<tsp> S;
		S.push({ 1, 0, 0, 0 });
		while (!S.empty()) {
			tsp data = S.top(); S.pop();
			if (DP[data.v][data.visit] < data.total) continue;

			if (HRAP[data.v][1] < INF) {
				int total = data.price - 2 * (data.total + HRAP[data.v][1]);
				if (result < total) {
					result = total;
					debug = data;
					debug.total += HRAP[data.v][1];
				}
			}

			if (DP[data.v][data.visit] >= data.total)
				DP[data.v][data.visit] = data.total;

			for (int k = 1; k < idx; k++) {
				if (!data.get(k) && GRAP[data.v][k] < INF) {
					tsp nxt = data;
					nxt.v = k;
					nxt.total = data.total + GRAP[data.v][k];
					nxt.set(k);
					S.push(nxt);
				}
			}
		}
		cout << debug.price << " - " << 2 * debug.total << endl;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (MAP[i][j] == 'E') cout << 'E';
				else cout << (debug.get(NNUM[i][j])? "*": ".");
			}
			cout << endl;
		}
		cout << result << endl;
		cout << endl;
	}
	return 0;
}

