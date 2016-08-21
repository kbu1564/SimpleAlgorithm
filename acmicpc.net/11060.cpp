#include <iostream>
using namespace std;
int DP[1001];
int main() {
	int N; cin >> N;
	for (int i = 0; i < 1001; i++) DP[i] = 1e9;

	DP[1] = 0;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		for (int j = i; j <= i + a && j <= N; j++) {
			DP[j] = min(DP[j], DP[i] + 1);
		}
	}
	cout << (DP[N] >= 1e9? -1: DP[N]) << endl;
	return 0;
}
