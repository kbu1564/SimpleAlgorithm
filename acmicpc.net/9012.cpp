#include <iostream>
using namespace std;
int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		char S[51] = { 0, };
		cin >> S;

		int result = 0;
		for (int j = 0; S[j]; j++) {
			if (S[j] == '(') result++;
			if (S[j] == ')') result--;
			if (result < 0) break;
		}
		cout << (result < 0 || result > 0? "NO": "YES") << endl;
	}
	return 0;
}
