#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	int result = 0;
	int N; cin >> N;
	queue<int> Q;
	Q.push(4); Q.push(7);
	while (!Q.empty()) {
		int data = Q.front(); Q.pop();
		if (data > N) continue;
		result = max(result, data);
		Q.push(data * 10 + 4);
		Q.push(data * 10 + 7);
	}
	cout << result << endl;
	return 0;
}

