#include <cstdio>
#include <iostream>
using namespace std;
int DP[255];
int main() {
	int maxLength = 0;
	char S[5001];
	while (cin >> S) {
		for (int i = 0; S[i] != 0; i++) {
			DP[S[i]]++;
			maxLength = max(maxLength, DP[S[i]]);
		}
	}
	for (int i = 0; i < 255; i++)
		if (DP[i] == maxLength)
			cout << (char)i;

	cout << endl;
	return 0;
}
