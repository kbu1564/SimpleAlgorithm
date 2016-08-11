#include <iostream>
#include <algorithm>
using namespace std;
int DP[100001][2]; // DP[i][j] = i��° �ٿ� ���ڰ� (j == 0 : ���� ���, j == 1 : �ִ� ���)
int main() {
	int N; cin >> N;
	DP[1][0] = 1;
	DP[1][1] = 2;
	for (int i = 2; i <= N; i++) {
		DP[i][0] = (DP[i - 1][0] + DP[i - 1][1]) % 9901;
		DP[i][1] = (DP[i - 1][0] * 2 + DP[i - 1][1]) % 9901;
	}
	cout << (DP[N][0] + DP[N][1]) % 9901 << endl;
	return 0;
}
