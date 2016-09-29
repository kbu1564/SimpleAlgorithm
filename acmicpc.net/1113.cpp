#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct item {
	int i, j;
};

int MAP[51][51];
int main() {
	int N, M;
	cin >> N >> M;

	int minHeight = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		char height; cin >> height;
		MAP[i][j] = height - '0';
	}
	for (int k = 1; k <= 9; k++) {
		int VIS[51][51] = { 0, };
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
			if (VIS[i][j] != 0) continue;
			/*
			for (i = 1 ~ 9) i보다 큰 수는 무조건 벽으로 간주
			*/
			queue<item> Q;
			Q.push({ i, j });
			while (!Q.empty()) {
				item data = Q.front(); Q.pop();
			}
		}
	}
	return 0;
}
