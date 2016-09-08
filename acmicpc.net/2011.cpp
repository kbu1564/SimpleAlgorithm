#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MOD = 1e6;

string PASS;
int DP[5001] = { 1, };

int main() {
	cin >> PASS;
	if (PASS[0] != '0') {
		for (int i = 1; i < PASS.length(); i++) {
			int two = (PASS[i-1]-'0') * 10 + (PASS[i]-'0');
			if (two == 0) break;
			if (two % 10 == 0) {
				if (two < 30) {
					DP[i] = (i-2 < 0? 1: DP[i-2]);
				}
				continue;
			}
			if (two >= 11 && two <= 26) {
				DP[i] = DP[i-1] + (i-2 < 0? 1: DP[i-2]);
			} else {
				DP[i] = DP[i-1];
			}
			DP[i] %= MOD;
		}
		printf("%d\n", DP[PASS.length()-1]);
	} else {
		printf("0\n");
	}
	
	return 0;
}
