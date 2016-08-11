#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct point { int x, y; };
int AX[4] = { -1, 1, 0, 0 }, AY[4] = { 0, 0, -1, 1 };
int main() {
	char M[26][26] = { 0, };
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> M[i][j];

	vector<int> v;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		if (M[i][j] == '0') continue;

		int area = 0;
		queue<point> Q;
		Q.push({ j, i });
		while (!Q.empty()) {
			point data = Q.front(); Q.pop();
			if (M[data.y][data.x] == '0') continue;
			M[data.y][data.x] = '0';
			area++;
			for (int k = 0; k < 4; k++) {
				int nx = data.x + AX[k], ny = data.y + AY[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (M[ny][nx] == '0') continue;
				Q.push({ nx, ny });
			}
		}
		v.push_back(area);
	}
	sort(v.begin(), v.end());

	int vlen = v.size();
	cout << vlen << endl;
	for (int i = 0; i < vlen; i++)
		cout << v[i] << endl;

	return 0;
}
