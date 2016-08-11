#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
enum { NONE = -1, UP, RIGHT, DOWN, LEFT };
struct node { int x, y, c; int dist; };

int N, INF = 987654321;
char M[51][51];
int V[51][51][4];
vector<node> p;

node mirror(node n, int type) {
	if (M[n.y][n.x] == '*') return n;

	V[n.y][n.x][n.dist]++;
	if (type == 0) {
		switch (n.dist) {
		case UP:    n.y++; break;
		case RIGHT: n.x--; break;
		case LEFT:  n.x++; break;
		case DOWN:  n.y--; break;
		}
	} else if (type == 1) {
		n.c++; // add mirror / !!
		switch (n.dist) {
		case UP:    n.x--; n.dist = RIGHT; break;
		case RIGHT: n.y++; n.dist = UP;    break;
		case LEFT:  n.y--; n.dist = DOWN;  break;
		case DOWN:  n.x++; n.dist = LEFT;  break;
		}
	} else if (type == 2) {
		n.c++; // add mirror \ !!
		switch (n.dist) {
		case UP:    n.x++; n.dist = LEFT;  break;
		case RIGHT: n.y--; n.dist = DOWN;  break;
		case LEFT:  n.y++; n.dist = UP;    break;
		case DOWN:  n.x--; n.dist = RIGHT; break;
		}
	}
	return n;
}
int main() {
	cin >> N;
	int mirrorCount = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		cin >> M[i][j];
		if (M[i][j] == '#') p.push_back({ j, i, 0, NONE });
		if (M[i][j] == '!') mirrorCount++;
	}

	// 거울에 반사해서 출발한 빛이 반대편에 부딛치게 된다는 것은
	// 거울의 방향을 반대로 하면 더 짧은 거울수로 나타내는 것이 가능하다는 것이다.
	int ans = INF;
	node s = p[0]; // start
	node e = p[1]; // end
	queue<node> Q;
	Q.push({ s.x, s.y, 0, UP });
	Q.push({ s.x, s.y, 0, RIGHT });
	Q.push({ s.x, s.y, 0, DOWN });
	Q.push({ s.x, s.y, 0, LEFT });
	while (!Q.empty()) {
		node data = Q.front(); Q.pop();
		cout << data.x << ", " << data.y << endl;
		if (data.x < 0 || data.y < 0 || data.x >= N || data.y >= N) continue;
		if (data.c > mirrorCount) continue;
		if (data.dist == UP && V[data.y][data.x][DOWN] > 0) continue;
		if (data.dist == DOWN && V[data.y][data.x][UP] > 0) continue;
		if (data.dist == LEFT && V[data.y][data.x][RIGHT] > 0) continue;
		if (data.dist == RIGHT && V[data.y][data.x][LEFT] > 0) continue;
		if (data.x == e.x && data.y == e.y) {
			ans = min(ans, data.c);
			continue;
		}
		char tile = M[data.y][data.x];
		if (tile != '*') {
			// 거울을 설치하지 않을 경우
			Q.push(mirror(data, 0));
			// 거울을 설치 할 경우
			if (tile == '!') {
				Q.push(mirror(data, 1));
				Q.push(mirror(data, 2));
			}
		}
	}
	cout << (ans == INF? 0: ans) << endl;
	return 0;
}

