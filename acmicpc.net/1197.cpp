#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int P[10001];
int  fi(int x) { return x == P[x] ? x : P[x] = fi(P[x]); }
void un(int x, int y) { P[fi(y)] = fi(x); }

struct node {
	int va, vb, e;
	bool operator<(const node& n) const { return e > n.e; }
};
int main() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 10001; i++) P[i] = i;

	int V, E; cin >> V >> E;

	int result = 0;
	priority_queue<node> Q;
	for (int i = 0; i < E; i++) {
		int va, vb, e; cin >> va >> vb >> e;
		Q.push({ va, vb, e });
	}
	while (!Q.empty()) {
		node data = Q.top(); Q.pop();
		if (fi(data.va) != fi(data.vb)) {
			result += data.e;
			un(data.va, data.vb);
		}
	}
	cout << result << endl;
	return 0;
}
