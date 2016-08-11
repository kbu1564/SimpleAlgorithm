#include <iostream>
using namespace std;
int main() {
	int N; cin >> N;
	long long DP[91][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, };
	for (int i = 3; i < 91; i++) {
		DP[i][0] = DP[i-1][0] + DP[i-1][1];
		DP[i][1] = DP[i-1][0];
	}
	cout << DP[N][0] + DP[N][1] << endl;
	return 0;
}
