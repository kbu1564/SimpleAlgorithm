#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int total = 0, s = 0;
		cin >> s; total += 9.23076 * pow(26.7 - s, 1.835);
		cin >> s; total += 1.84523 * pow(s - 75, 1.348);
		cin >> s; total += 56.0211 * pow(s - 1.5, 1.05);
		cin >> s; total += 4.99087 * pow(42.5 - s, 1.81);
		cin >> s; total += 0.188807 * pow(s - 210, 1.41);
		cin >> s; total += 15.9803 * pow(s - 3.8, 1.04);
		cin >> s; total += 0.11193 * pow(254 - s, 1.88);
		cout << total << endl;
	}
	return 0;
}
