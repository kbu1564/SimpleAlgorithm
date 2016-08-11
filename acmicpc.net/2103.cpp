#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int temp = 0;
	temp += x1*y2 + x2*y3 + x3*y1;
	temp -= y1*x2 - y2*x3 - y3*x1;
	if (temp > 0) return 1;
	if (temp < 0) return -1;
	return 0;
}
vector<int> xvec[10001];
vector<int> yvec[10001];
int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		xvec[x].push_back(y);
		yvec[y].push_back(x);
	}

	for (int i = 0; i < N; i++) {
		sort(xvec[i].begin(), xvec[i].end());
		sort(yvec[i].begin(), yvec[i].end());
	}

	int result = 0;
	pair<int, int> p1, p2, p3;
	cout << result << endl;
	return 0;
}
