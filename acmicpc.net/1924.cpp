#include <iostream>
using namespace std;
int DP[13][32];
int MONTH[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char STAT[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int main() {
	int m, d; cin >> m >> d;

	int stat = 1;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= MONTH[i]; j++) {
			DP[i][j] = (stat++) % 7;
		}
	}
	cout << STAT[DP[m][d]] << endl;
	return 0;
}
