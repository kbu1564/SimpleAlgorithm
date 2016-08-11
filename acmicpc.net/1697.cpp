#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 600001;
struct status {
	int idx;
	int time;
};
int N, K, f, r, DP[100001];
status Q[SIZE];
int main() {
	for (int i = 0; i < 100001; i++) DP[i] = 1e9;

	cin >> N >> K;

	Q[r++] = { N, 0 };
	r %= SIZE;
	while (f != r) {
		status curr = Q[f++];
		f %= SIZE;

		if (curr.idx > 100000 || curr.idx < 0) continue;
		if (DP[curr.idx] < curr.time) continue;
		if (curr.idx == K) {
			DP[curr.idx] = min(DP[curr.idx], curr.time);
		} else {
			DP[curr.idx] = curr.time;
		}

		Q[r++] = { curr.idx + 1, curr.time + 1 };
		r %= SIZE;
		Q[r++] = { curr.idx - 1, curr.time + 1 };
		r %= SIZE;
		Q[r++] = { curr.idx * 2, curr.time + 1 };
		r %= SIZE;
	}
	cout << DP[K] << endl;
	return 0;
}