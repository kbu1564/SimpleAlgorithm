#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct node {
	int i, total, start;
	int visit;
	void sv(int n) { visit = visit | (1 << n); }
	bool gv(int n) { return (visit & (1 << n)) > 0; }
};

int DP[17][65536];
int MAP[17][17];
int main() {
	for (int i = 0; i < 17; i++)
		for (int j = 0; j < 65536; j++)
			DP[i][j] = 1e9;

	int N; cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];

	int result = 1e9;
	int maxVisit = 0;
	for (int i = 0; i < N; i++) maxVisit = maxVisit | (1 << i);
	for (int i = 0; i < N; i++) {
		stack<node> S;
		S.push({ i, 0, i, (1 << i) });
		while (!S.empty()) {
			node data = S.top(); S.pop();
			if (data.total >= result) continue;
			if (DP[data.i][data.visit] <= data.total) continue;
			DP[data.i][data.visit] = data.total;

			if (data.visit == maxVisit && data.total > 0 && MAP[data.i][data.start] > 0) {
				result = min(result, data.total + MAP[data.i][data.start]);
			} else {
				for (int j = 0; j < N; j++) {
					if (!data.gv(j) && MAP[data.i][j] > 0) {
						if (data.total + MAP[data.i][j] >= result) continue;
						node next = data;
						next.i = j;
						next.total += MAP[data.i][j];
						next.sv(j);
						S.push(next);
					}
				}
			}
		}
	}
	cout << result << endl;
	return 0;
}
