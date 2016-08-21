#include <iostream>
using namespace std;

int DP[1001];
int main() {
	int N, K; cin >> N >> K;

	int result = 0;
	int removeCount = 0;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; i * j <= N; j++) {
			if (DP[i*j] == 0) {
				DP[i*j] = 1; removeCount++;
				if (removeCount == K) {
					cout << i*j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
