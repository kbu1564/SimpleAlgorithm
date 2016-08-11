#include <iostream>
using namespace std;
int DP[1000001] = { 0, 1, 2 };
int main() {
	int N; cin >> N;
	for (int i = 3; i <= N; i++) {
		DP[i] = (DP[i-1] + DP[i-2]) % 15746;
	}
	cout << DP[N] << endl;
	return 0;
}
