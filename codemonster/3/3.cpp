#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

const int INF = -2e9;
const int MAX = 51;

int T, N, K, W;
vector<pair<int, int>> XY;

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d %d", &N, &K, &W);

		priority_queue<int, vector<int>, less<int>> maxxh;
		priority_queue<int, vector<int>, greater<int>> minxh;
		for (int i = 0; i < N; i++) {
			int x, y; scanf("%d %d", &x, &y);

			XY.push_back(pair<int, int>(x, y));
			minxh.push(x); maxxh.push(x);
		}

		sort(XY.begin(), XY.end());

		int left = minxh.top(); minxh.pop();
		int right = maxxh.top(); maxxh.pop();
		for (;;) {
			if (minxh.empty() || maxxh.empty()) break;
			if (left >= right) break;
		}
	}
	return 0;
}
