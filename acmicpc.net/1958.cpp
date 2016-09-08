#include <iostream>
#include <string>
using namespace std;
int DP[101][101][101];

string s1, s2, s3;
int lcs(int i, int j, int k) {
	if (i < 0 || j < 0 || k < 0) return 0;
	if (DP[i][j][k] > 0) return DP[i][j][k];
	if (s1[i] == s2[j] && s2[j] == s3[k]) return DP[i][j][k] = lcs(i-1, j-1, k-1) + 1;
	if (s1[i] == s2[j] && s2[j] != s3[k]) return DP[i][j][k] = lcs(i, j, k-1);
	if (s1[i] != s2[j] && s2[j] == s3[k]) return DP[i][j][k] = lcs(i-1, j, k);
	if (s1[i] == s3[k] && s1[i] != s2[j] && s2[j] != s3[k]) return DP[i][j][k] = lcs(i, j-1, k);
	return DP[i][j][k];
}

int main() {
	cin >> s1 >> s2 >> s3;
	cout << lcs(s1.length()-1, s2.length()-1, s3.length()-1) << endl;
	return 0;
}
