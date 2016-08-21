#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char P[101];
char FN[101];
int LCS[101][101];
int lcs(int i, int j) {
	if (i < 0 || j < 0) return 0;
	if (LCS[i][j] > 0) return LCS[i][j];
	if (P[i] != '*') {
		if (P[i] == FN[j]) return LCS[i][j] = max(LCS[i][j], lcs(i-1, j-1) + 1);
		return LCS[i][j];
	}
	return LCS[i][j] = max(LCS[i][j], max(lcs(i-1, j), lcs(i, j-1)));
}
int main() {
	cin >> P;
	int lp = strlen(P);

	int alphaCount = 0;
	char INP[101] = { 0, };
	for (int i = 0; P[i]; i++) if (P[i] != '*') INP[alphaCount++] = P[i];

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 101; j++) for (int k = 0; k <= 101; k++) LCS[j][k] = 0;

		cin >> FN;

		int lcsCount = lcs(lp-1, strlen(FN)-1);
		if (lcsCount == alphaCount) cout << FN << endl;
	}
	return 0;
}

