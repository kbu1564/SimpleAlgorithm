#include <iostream>
using namespace std;
int N;
int result;
int MAP[16][16];
int CKX[16], CKY[16];
int SETX[16];
void dfs(int x, int y) {
	if (CKX[x] == 1 || CKY[y] == 1) return;

	for (int i = 1; i < x; i++)
		if (abs(SETX[i] - y) == abs(i - x))
			return;

	MAP[x][y] = 1;
	CKX[x] = CKY[y] = 1;
	SETX[x] = y;
	if (x < N) {
		for (int i = 1; i <= N; i++) dfs(x+1, i);
	} else if (x == N) {
		result++;
	}
	SETX[x] = 0;
	CKX[x] = CKY[y] = 0;
	MAP[x][y] = 0;
}
int main() {
	cin >> N;
	dfs(0, 0);
	cout << result << endl;
	return 0;
}
