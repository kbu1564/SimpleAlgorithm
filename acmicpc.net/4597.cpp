#include <iostream>
using namespace std;
int main() {
	for (;;) {
		char S[32] = { 0, };
		cin >> S;
		if (S[0] == '#') break;
		int one = 0;
		int zer = 0;
		char pa = 0;
		for (int i = 0; S[i]; i++) {
			if (S[i] == '1') one++;
			if (S[i] == '0') zer++;
			if (S[i] == '1' || S[i] == '0') cout << S[i];
			pa = S[i];
		}
		if (pa == 'e') {
			cout << (one % 2 == 1? '1': '0') << endl;
		} else {
			cout << (one % 2 == 0? '1': '0') << endl;
		}
	}
	return 0;
}
