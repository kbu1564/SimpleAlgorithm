#include <iostream>
#include <string>
using namespace std;
int main() {
	int N = -1;
	while (N != 0) {
		string result = "POSSIBLE";
		int IN[1423] = { 0, };
		int DP[1423] = { 0, };
		for (int i = 0; i < 1423; i++) DP[i] = -1;

		cin >> N;
		if (N <= 0) break;

		int last = 0;
		for (int i = 0; i < N; i++) {
			int NI; cin >> NI;
			IN[NI] = 1;
			// 더슨 -> 델타 마지막 충전소
			last = max(last, NI);
		}

		if (IN[0] > 0) DP[0] = 200;

		// 더슨 -> 델타
		for (int i = 0; i <= 1422; i++) {
			if (DP[i] < 0) break;
			if (DP[i] == 0 && IN[i] == 0) break;
			if (IN[i] == 0) continue;

			DP[i] = 200;
			for (int j = 1; j <= 200; j++) {
				if (i + j < 1423) {
					DP[i+j] = max(DP[i+j], DP[i]-j);
				}
			}
		}

		// 더슨 -> 델타 못가면 여행 실패
		if (DP[1422] < 0)
			result = "IMPOSSIBLE";
		else {
			// 1422에서 다시 델타로 돌아가는 도중
			// 만나게 되는 첫번째 충전소까지 이동이 가능한지만 체크
			if (DP[1422] < 1422 - last) result = "IMPOSSIBLE";
			/*
			// 0 ~ 1421 까지 초기화
			for (int i = 0; i < 1422; i++) DP[i] = -1;

			if (IN[1422] > 0) DP[0] = 200;
			// 델타-> 더슨
			for (int i = 1422; i >= 0; i--) {
				if (DP[i] < 0) break;
				if (DP[i] == 0 && IN[i] == 0) break;
				if (IN[i] == 0) continue;

				DP[i] = 200;
				for (int j = 1; j <= 200; j++) {
					if (i - j >= 0) {
						DP[i-j] = max(DP[i-j], DP[i]-j);
					}
				}
			}
			if (DP[0] < 0)
				result = "IMPOSSIBLE";
			*/
		}
		cout << result << endl;
	}

	return 0;
}
