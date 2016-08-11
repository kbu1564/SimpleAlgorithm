#include <iostream>
#include <algorithm>
using namespace std;
int ARR[301];
// i 번째 계단에 도착할때 1칸을 j번만큼 연속으로 밟고 도착한 최대점수
int DP[301][3];
int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> ARR[i];
	for (int i = 1; i <= N; i++) {
		DP[i][2] = ARR[i] + (i > 0? DP[i-1][1]: 0);
		DP[i][1] = ARR[i] + (i > 1? max(DP[i-2][1], DP[i-2][2]): 0);
		// i 2칸 연속으로 밟은 경우 = i-1 1칸 연속으로 밟은 경우
		// i 1칸 연속으로 밟은 경우 = i-2 1칸 연속으로 밟은 경우, i-2 2칸 연속으로 밟은 경우
	}
	cout << max(DP[N][1], DP[N][2]) << endl;
	return 0;
}
