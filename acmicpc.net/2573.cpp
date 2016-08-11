#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point {
	int x, y;
};

int MAP[301][301];
int main() {
	int N, M;
	cin >> N >> M;
	int minHeight = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			minHeight = min(minHeight, MAP[i][j]);
		}
	}

	for (int k = 1; k < 11; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				MAP[i][j] -= minHeight;
			}
		}
		queue<point> Q;
		Q.push({  });
		while (!Q.empty()) {
			point data = Q.front(); Q.pop();
		}
	}
	return 0;
}
