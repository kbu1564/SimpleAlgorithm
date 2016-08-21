#include <iostream>
using namespace std;
const int SIZE = 10001;
int Q[SIZE], f, r, c;
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		char cmd[10]; cin >> cmd;
		if (cmd[0] == 'p') {
			if (cmd[1] == 'u') {
				int ni; cin >> ni;
				Q[r=(r+1)%SIZE] = ni; c++;
			}
			if (cmd[1] == 'o') {
				if (f != r) c--;
				cout << (f != r? Q[f=(f+1)%SIZE]: -1) << endl;
			}
		}
		if (cmd[0] == 's') {
			cout << c << endl;
		}
		if (cmd[0] == 'e') {
			cout << (c <= 0? 1: 0) << endl;
		}
		if (cmd[0] == 'f') {
			cout << (f != r? Q[(f+1)%SIZE]: -1) << endl;
		}
		if (cmd[0] == 'b') {
			cout << (f != r? Q[r%SIZE]: -1) << endl;
		}
	}
	return 0;
}
