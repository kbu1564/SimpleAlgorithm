#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int x, y, b;
};
const int MAXW = 101;
const int MAXDP = MAXW/2*MAXW;
const int SIZE = 500000;
const int INF = 1e9;
const int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
int MAP[MAXW][MAXW], VIS[MAXW][MAXW];
int A[MAXW][MAXW];
int DP[MAXDP][MAXDP];
node Q[SIZE];
int main() {
	int f = 0, r = 0;
	int N; cin >> N;
	for (int i = 0; i < MAXDP; i++) for (int j = 0; j < MAXDP; j++) DP[i][j] = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			A[i][j] = INF;
		}
	}

	// 영역 개수
	int idx = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (VIS[i][j] > 0 || MAP[i][j] == 0) continue;

			int areaNumber = idx++;
			// 영역별 번호 부여
			f = 0, r = 0;
			Q[r++] = { j, i, 0 };
			r %= SIZE;
			while (f != r ) {
				node data = Q[f++];
				f %= SIZE;
				if (data.x < 0 || data.y < 0 || data.x >= N || data.y >= N) continue;
				if (MAP[data.y][data.x] == 0) continue;
				if (VIS[data.y][data.x] > 0) continue;
				VIS[data.y][data.x] = areaNumber;

				for (int k = 0; k < 4; k++) {
					int nx = data.x + AX[k];
					int ny = data.y + AY[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (MAP[ny][nx] == 0) continue;
					if (VIS[ny][nx] > 0) continue;
					Q[r++] = { nx, ny, data.b + (MAP[ny][nx] == 0) };
					r %= SIZE;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (VIS[i][j] == 0) continue;

			int areaNumber = VIS[i][j];
			// 최소 다리 길이 구하기
			f = 0, r = 0;
			Q[r++] = { j, i, 0 };
			r %= SIZE;
			while (f != r) {
				node data = Q[f++];
				f %= SIZE;
				if (data.x < 0 || data.y < 0 || data.x >= N || data.y >= N) continue;
				if (A[data.y][data.x] > data.b)
					A[data.y][data.x] = data.b;
				else
					continue;

				// areaNumber 로 부터 다른 영역까지 가기위한 최소 다리 길이
				if (areaNumber != INF && VIS[data.y][data.x] != INF)
					if (MAP[data.y][data.x] == 1 && VIS[data.y][data.x] != areaNumber)
						DP[areaNumber][VIS[data.y][data.x]] = min(DP[areaNumber][VIS[data.y][data.x]], data.b);

				for (int k = 0; k < 4; k++) {
					int nx = data.x + AX[k];
					int ny = data.y + AY[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					Q[r++] = { nx, ny, data.b + (MAP[ny][nx] == 0) };
					r %= SIZE;
				}
			}
		}
	}

	// 시작점에 속하는 영역의 값을 0으로 셋팅
	/*
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == 1) cout << ". ";
			else cout << (A[i][j] == INF? 0: A[i][j]) << " ";
		}
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == 0) cout << ". ";
			else cout << VIS[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < idx; i++) {
		for (int j = i + 1; j < idx; j++) {
			cout << i << " => " << j << " : " << DP[i][j] << endl;
		}
	}
	*/

	int ans = INF;	
	for (int i = 0; i < idx; i++) for (int j = i + 1; j < idx; j++) ans = min(ans, DP[i][j]);

	cout << ans << endl;
	return 0;
}
