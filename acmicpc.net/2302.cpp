#include <iostream>
using namespace std;

int VIP[41] = { 0, };
int DP[41] = { 1, 1, };

int main() {
	int N; cin >> N;
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int vip; cin >> vip;
		VIP[vip] = 1;
	}

	for (int i = 2; i <= N; i++) {
		if (VIP[i] == 1 || VIP[i-1] == 1) {
			DP[i] = DP[i-1];
		} else {
			// DP[i] = DP[i-1] 의 뒤에 모두 i가 오는 경우 + DP[i-2] 의 뒤에 i가 i-1과 자리를 바꾸는 경우
			DP[i] = DP[i-1] + DP[i-2];
		}
	}

	cout << DP[N] << endl;
	return 0;
}
