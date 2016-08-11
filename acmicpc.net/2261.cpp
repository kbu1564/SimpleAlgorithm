#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
struct point {
	int x, y;
	bool operator<(const point& p) {
		return x < p.x || (x == p.x && y < p.y);
	}
};
set<point> xy;
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int X, Y; scanf("%d %d", &X, &Y);
		X += 10000, Y += 10000;
		xy.insert({ X, Y });
	}
	int result = 1e9;
	return 0;
}
