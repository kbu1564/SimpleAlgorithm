#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct info {
	int l, r;
};
struct infoi {
	int i, l, r;
	bool operator<(const infoi& n) const {
		return (l < n.l && r > n.r) || (l == n.l && r > n.r) || (l < n.l && r == n.r);
	}
};
info A[500001];
int DP[500001];
int N;
// r1 > r2
int solve(int node) {
	if (DP[node] > 0) return DP[node];
	int rst = 1;
	info& r2 = A[node];
	for (int i = 1; i <= N; i++) {
		if (i == node) continue;

		info& r1 = A[i];
		if ((r1.l < r2.l && r1.r > r2.r) || (r1.l == r2.l && r1.r > r2.r) || (r1.l < r2.l && r1.r == r2.r)) {
			rst = max(rst, solve(i) + 1);
		}
	}
	return DP[node] = rst;
}

//vector<pair<int, int>> vec;
vector<infoi> vec;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int idx, l, r;
		scanf("%d %d %d", &idx, &l, &r);
		A[idx] = { l, r };
		//vec.push_back(pair<int, int>(l, r));
		vec.push_back({ idx, l, r });
	}

	sort(vec.begin(), vec.end());
	for (auto v : vec) {
		cout << v.i << " : " << v.l << " ~ " << v.r << endl;
	}
	/*
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, solve(i));
	}
	cout << ans << endl;
	*/
	return 0;
}

