#include <iostream>
#include <algorithm>
using namespace std;
int DP[1001] = { 0, 1, 2, 3, 5, };
int main() {
	int N; cin >> N;
	for (int i = 5; i <= N; i++) {
		DP[i] = (DP[i-1] + DP[i-2]) % 10007;
	}
	cout << DP[N] << endl;
	return 0;
}
