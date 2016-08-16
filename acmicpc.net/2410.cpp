#include <iostream>
using namespace std;
int DP[1000001];
int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i<<=1) {
		for (int j = 1; j <= N; j++) {
			if (j >= i)
				DP[j] = DP[j-i] + 1;
		}
	}
	cout << DP[N] % 1e9 << endl;
	return 0;
}
