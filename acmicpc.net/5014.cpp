#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int F, S, G, U, D;
struct floors {
	int curr;
	int count;
};
int DP[1000001];
int main() {
	cin >> F >> S >> G >> U >> D;
	if (S > G) {
		int t = 0;
		t = S;
		S = G;
		G = t;

		t = U;
		U = D;
		D = t;
	}

	for (int i = 0; i < 1000001; i++) DP[i] = 1e9;
	if (U > 0 && (G - S) % U == 0) {
		cout << (G - S) / U << endl;
		return 0;
	}

	queue<floors> Q;
	Q.push({ S, 0 });
	while (!Q.empty()) {
		floors data = Q.front(); Q.pop();
		if (data.curr < 1 || data.curr > F) continue;
		if (DP[data.curr] <= data.count) continue;
		DP[data.curr] = data.count;
		if (data.curr == G) continue;

		int up = data.curr + U;
		int down = data.curr - D;
		if (data.curr != up)
			Q.push({ up, data.count + 1 });
		if (data.curr != down)
			Q.push({ down, data.count + 1 });
	}

	if (DP[G] < 1e9)
		cout << DP[G] << endl;
	else
		cout << "use the stairs" << endl;

	return 0;
}