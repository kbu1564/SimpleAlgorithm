#include <iostream>
using namespace std;
int P[1001];
int main() {
	int T; cin >> T;
	for (int ii = 0; ii < T; ii++) {
		int N; cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> P[i];
		}

		int result = 0;
		int DP[1001] = { 0, };
		for (int i = 1; i <= N; i++) {
			if (DP[i] > 0) continue;
			int root = P[i];
			while (root != i) {
				DP[root] = i;
				root = P[root];
			}
			result++;
		}
		cout << result << endl;
	}
	return 0;
}
