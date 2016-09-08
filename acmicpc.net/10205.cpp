#include <iostream>
#include <string>
using namespace std;

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int h; cin >> h;
		string AC; cin >> AC;

		cout << "Data Set " << tc << ": " << endl;
		for (int i = 0; i < AC.length(); i++) {
			if (AC[i] == 'c') {
				h++;
			}
			if (AC[i] == 'b') {
				h--;
			}
		}
		cout << (h <= 0? 0: h) << endl << endl;
	}
	return 0;
}
