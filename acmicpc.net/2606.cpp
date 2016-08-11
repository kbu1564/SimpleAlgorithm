#include <iostream>
using namespace std;
const int INF = 987654321;
int main() {
	int N; cin >> N;
	int M; cin >> M;
	int ARR[101][101] = { 0, };
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			ARR[i][j] = INF;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ARR[a][a] = ARR[b][b] = 0;
		ARR[a][b] = ARR[b][a] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (ARR[i][j] > ARR[i][k] + ARR[k][j])
					ARR[i][j] = ARR[i][k] + ARR[k][j];

	int rst = 0;
	for (int i = 1; i <= N; i++)
		if (ARR[1][i] < INF && ARR[1][i] > 0)
			rst++;

	cout << rst << endl;
	return 0;
}
