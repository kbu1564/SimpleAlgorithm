#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> Q;
	int N; cin >> N;
	for (int i = 1; i <= N; i++) Q.push(i);
	while (!Q.empty()) {
		int top1 = Q.front();
		cout << Q.front() << ' ';
		Q.pop();
		int top2 = Q.front(); Q.pop();
		Q.push(top2);
	}
	return 0;
}
