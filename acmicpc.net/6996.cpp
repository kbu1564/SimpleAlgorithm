#include <iostream>
using namespace std;

char S1[101], S2[101];
int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> S1 >> S2;

		int A1[255] = { 0, }, A2[255] = { 0, };
		for (int i = 0; S1[i]; i++) A1[S1[i]]++;
		for (int i = 0; S2[i]; i++) A2[S2[i]]++;

		int result = 1;
		for (int i = 0; i < 255; i++) {
			if (A1[i] != A2[i]) {
				result = 0; break;
			}
		}
		cout << S1 << " & " << S2 << " are " << (result == 0? "NOT ": "") << "anagrams." << endl;
	}
	return 0;
}
