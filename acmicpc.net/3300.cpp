#include <iostream>
#include <stack>
#include <string>
using namespace std;

string S1, S2;

int main() {
	ios::sync_with_stdio(false);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> S1 >> S2;

		S1 = '(' + S1 + ')';

		stack<string> blocks;
		stack<char> S;
		for (int i = 0; i < S1.length(); i++) {
			if (S1[i] == ')') {
				string pices;
				while (!S.empty()) {
					char word = S.top(); S.pop();
					if (word == '(') break;
					pices = word + pices;
				}

				// | 기준으로 분리
				int piceCount = 0;
				string pice;

				pices += '|';
				for (int j = 0; j < pices.length(); j++) {
					if (pices[j] == '|') {
						piceCount++;
						blocks.push(pice);
						pice = "";
					} else {
						pice += pices[j];
					}
				}

				for (int j = 0; j < piceCount; j++) S.push('*');
			} else {
				S.push(S1[i]);
			}
		}

		string original;
		while (!S.empty()) {
			if (S.top() == '*') {
				cout << blocks.top(); blocks.pop();
			} else {
				cout << S.top();
			}
			S.pop();
		}
		cout << endl;
	}
	return 0;
}
