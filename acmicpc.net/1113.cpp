#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct item {
	int i, j;
};

int MAP[51][51];
int AX[] = { 0, 0, 1, -1 }, AY[] = { 1, -1, 0, 0 };
int DP[51][51];
int AN[51][51];
int AR[2501];
int main() {
	int N, M;
	cin >> N >> M;

	/*
	만약 영역 개수검사를 실시 하였는데 9 부터 1씩 감소하면서 체크한 영역의 개수가 1개일 경우 1씩 감소
	영역의 개수가 1개이상이 되는순간 해당 영역은 물이 고일 수 있는 구간으로 판단

	테두리 부분만 루프 돌면서 영역개수 검사
	*/
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		char height; cin >> height;
		MAP[i][j] = height - '0';
	}

	int areaNumber = 1;
	int maxAreaCount = 0;
	for (int k = 1; k <= 9; k++) {
		int VIS[51][51] = { 0, };

		// 테두리 부분은 넓이 체크 대상에서 제외
		queue<item> RQ;
		for (int i = 0; i < N; i++) {
			// j = 0 && j = M-1
			RQ.push({ i, 0 }); RQ.push({ i, M-1 });
		}
		for (int j = 0; j < M; j++) {
			// i = 0 && i = N-1
			RQ.push({ 0, j }); RQ.push({ N-1, j });
		}
		while (!RQ.empty()) {
			item data = RQ.front(); RQ.pop();
			if (data.i < 0 || data.j < 0 || data.i >= N || data.j >= M) continue;
			if (MAP[data.i][data.j] >= k) continue;
			if (VIS[data.i][data.j] > 0) continue;
			VIS[data.i][data.j] = 1;

			for (int x = 0; x < 4; x++) {
				int ni = AY[x] + data.i;
				int nj = AX[x] + data.j;
				if (MAP[ni][nj] < k) {
					RQ.push({ ni, nj });
				}
			}
		}

		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
			if (VIS[i][j] != 0) continue;

			int areaSize = 0;
			queue<item> Q;
			Q.push({ i, j });
			while (!Q.empty()) {
				item data = Q.front(); Q.pop();
				if (data.i < 0 || data.j < 0 || data.i >= N || data.j >= M) continue;
				if (MAP[data.i][data.j] >= k) continue;
				if (VIS[data.i][data.j] > 0) continue;
				VIS[data.i][data.j] = 1;
				areaSize += k - MAP[data.i][data.j];

				for (int x = 0; x < 4; x++) {
					int ni = AY[x] + data.i;
					int nj = AX[x] + data.j;
					if (MAP[ni][nj] < k) {
						Q.push({ ni, nj });
					}
				}
			}

			if (areaSize > 0) {
				queue<item> DQ;
				DQ.push({ i, j });
				while (!DQ.empty()) {
					item data = DQ.front(); DQ.pop();
					if (data.i < 0 || data.j < 0 || data.i >= N || data.j >= M) continue;
					if (MAP[data.i][data.j] >= k) continue;
					if (DP[data.i][data.j] >= areaSize)
						continue;

					if (AN[data.i][data.j] <= areaNumber)
						AN[data.i][data.j] = areaNumber;

					DP[data.i][data.j] = areaSize;
					for (int x = 0; x < 4; x++) {
						int ni = AY[x] + data.i;
						int nj = AX[x] + data.j;
						if (MAP[ni][nj] < k) {
							DQ.push({ ni, nj });
						}
					}
				}
				areaNumber++;
			}
		}
		maxAreaCount = max(maxAreaCount, areaNumber);
	}

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << AN[i][j] << " ";
		}
		cout << endl;
	}
	*/

	for (int k = 1; k <= maxAreaCount; k++) {
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
			if (AN[i][j] == k) AR[k] = max(AR[k], DP[i][j]);
		}
		//cout << k << " : " << AR[k] << endl;
	}

	int result = 0;
	for (int k = 1; k <= maxAreaCount; k++) result += AR[k];
	cout << result << endl;
	return 0;
}

