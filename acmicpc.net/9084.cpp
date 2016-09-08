#include <iostream>
using namespace std;
int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int DP[10001] = { 0, };
		int COIN[21] = { 0, };
		int N; cin >> N;
		for (int j = 0; j < N; j++) cin >> COIN[j];
		int M; cin >> M;

		DP[0] = 1;
		for (int j = 0; j < N; j++) {
			for (int k = COIN[j]; k <= M; k++) {
				DP[k] += DP[k-COIN[j]];
			}
		}
		cout << DP[M] << endl;
	}
	return 0;
}
