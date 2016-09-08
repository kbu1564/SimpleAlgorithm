#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string S[7] = {
		"",
		"Yakk",
		"Doh",
		"Seh",
		"Ghar",
		"Bang",
		"Sheesh"
	};

	string SS[7][7];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			SS[i][j] += S[max(i, j)];
			SS[i][j] += ' ';
			SS[i][j] += S[min(i, j)];
		}
	}
	SS[1][1] = "Habb Yakk";
	SS[2][2] = "Dobara";
	SS[3][3] = "Dousa";
	SS[4][4] = "Dorgy";
	SS[5][5] = "Dabash";
	SS[6][6] = "Dosh";
	SS[5][6] = SS[6][5] = "Sheesh Beesh";

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int a, b; cin >> a >> b;
		cout << "Case " << tc << ": " << SS[a][b] << endl;
	}
	
	return 0;
}
