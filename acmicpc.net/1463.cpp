#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int DP[100001] = { 0, 0, 1, 1, };
int main() {
	int N; cin >> N;
	for (int i = 4; i < 100001; i++) DP[i] = INF;
	for (int i = 4; i < 100001; i++) {
		if (i - 1 >= 0) DP[i] = min(DP[i], DP[i-1] + 1);
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i/2] + 1);
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i/3] + 1);
	}
	cout << DP[N] << endl;
	return 0;
}

