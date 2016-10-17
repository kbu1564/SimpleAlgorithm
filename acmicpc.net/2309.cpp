#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node {
	int n, vis, c, k;
};

int N[10];
int main() {
	for (int i = 1; i <= 9; i++) {
		cin >> N[i];
	}

	vector<int> result;
	queue<node> Q;
	Q.push({ 0, 0, 0, 0 });
	while (!Q.empty()) {
		node data = Q.front(); Q.pop();
		if (data.n > 9) continue;
		if (data.c == 7 && data.k == 100) {
			// answer
			for (int i = 1; i <= 9; i++) {
				if ((data.vis & (1 << i)) > 0) {
					result.push_back(N[i]);
				}
			}
			break;
		}
		if (data.n + 1 < 10) {
			Q.push({ data.n + 1, data.vis, data.c, data.k });
			Q.push({ data.n + 1, data.vis | (1 << (data.n + 1)), data.c + 1, data.k + N[data.n+1] });
		}
	}
	sort(result.begin(), result.end());
	for(auto& n : result)
		cout << n << endl;

	return 0;
}
