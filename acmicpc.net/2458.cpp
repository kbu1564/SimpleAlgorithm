#include <iostream>
using namespace std;
int INF = 1e9;
int ST[501][501];
int BT[501][501];
int main() {
	int N; cin >> N;
	int M; cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		BT[a][b] = 1;
		ST[b][a] = 1;
	}

	// 자기보다 큰사람 찾기
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (BT[i][j] == 0 && BT[i][k] == 1 && BT[k][j] == 1)
					BT[i][j] = 1;

	// 자기보다 작은사람 찾기
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (ST[i][j] == 0 && ST[i][k] == 1 && ST[k][j] == 1)
					ST[i][j] = 1;

	int result = 0;
	for (int i = 1; i <= N; i++) {
		int big = 0;
		int small = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (ST[i][j] == 1)
				small++;
			if (BT[i][j] == 1)
				big++;
		}
		if (small + big + 1 == N)
			result++;
	}
	cout << result << endl;
	return 0;
}