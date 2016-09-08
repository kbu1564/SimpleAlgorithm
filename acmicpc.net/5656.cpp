#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int tc = 1;
	while (1) {
		int a, b;
		char c[5];
		cin >> a >> c >> b;
		if (c[0] == 'E') break;

		cout << "Case " << tc << ": ";
		if (c[1] == 0) {
			if (c[0] == '>') {
				cout << (a > b? "true": "false") << endl;
			}
			if (c[0] == '<') {
				cout << (a < b? "true": "false") << endl;
			}
		} else {
			if (c[0] == '>') {
				cout << (a >= b? "true": "false") << endl;
			}
			if (c[0] == '<') {
				cout << (a <= b? "true": "false") << endl;
			}
			if (c[0] == '=') {
				cout << (a == b? "true": "false") << endl;
			}
			if (c[0] == '!') {
				cout << (a != b? "true": "false") << endl;
			}
		}
		tc++;
	}
	return 0;
}
