#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int DP[4001][4001];
string S1, S2;
int solve(int s1len, int s2len) {
	if (s1len < 0 || s2len < 0) return 0;
	if (DP[s1len][s2len] > 0) return DP[s1len][s2len];
	if (S1[s1len] == S2[s2len]) return DP[s1len][s2len] = solve(s1len-1, s2len-1) + 1;
	return 0;
}
int main() {
	cin >> S1 >> S2;
	int result = 0;
	int s1len = S1.length();
	int s2len = S2.length();
	for (int i = s1len-1; i >= 0; i--)
		for (int j = s2len-1; j >= 0; j--)
			result = max(result, solve(i, j));

	cout << result << endl;
	return 0;
}
