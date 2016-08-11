#include <iostream>
#include <queue>
using namespace std;
int MM[1001][1001], N, M;
enum { UP, RIGHT, DOWN, LEFT };
struct node { int x, y, dist; };
queue<node> Q;
node dist(node n) {
	if (MM[n.y][n.x] == 1) {
		switch (n.dist) {
		case UP:    n.x--; n.dist = RIGHT; break;
		case RIGHT: n.y++; n.dist = UP; break;
		case DOWN:  n.x++; n.dist = LEFT; break;
		case LEFT:  n.y--; n.dist = DOWN; break;
		}
	} else {
		switch (n.dist) {
		case UP:    n.y++; break;
		case RIGHT: n.x--; break;
		case DOWN:  n.y--; break;
		case LEFT:  n.x++; break;
		}
	}
	return n;
}
node P[4001];
int main() {
	int idx = 1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> MM[i][j];

	for (int i = 0; i < N; i++) {
		P[idx++] = { -1, i, RIGHT }; Q.push({ 0, i, LEFT });
	}
	for (int j = 0; j < M; j++) {
		P[idx++] = { j, N, UP }; Q.push({ j, N-1, DOWN });
	}
	for (int i = N-1; i >= 0; i--) {
		P[idx++] = { M, i, LEFT }; Q.push({ M-1, i, RIGHT });
	}
	for (int j = M-1; j >= 0; j--) {
		P[idx++] = { j, -1, DOWN }; Q.push({ j, 0, UP });
	}

	int input = 1;
	while (!Q.empty()) {
		node data = Q.front(); Q.pop();
		node next = data;
		while (next.x >= 0 && next.y >= 0 && next.x < M && next.y < N) next = dist(next);

		for (int i = 1; i < 4001; i++) {
			if (P[i].x == next.x && P[i].y == next.y) {
				cout << i << " ";
				break;
			}
		}
	}
	return 0;
}
