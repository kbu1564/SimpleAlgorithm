#include <iostream>
using namespace std;
char CD[51][51];
int main() {
	int R, C; cin >> R >> C;
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> CD[i][j];
	int A, B; cin >> A >> B;
	int ii = 0;
	for (int i = 0; i < R; i++, ii++) {
		int jj = 0;
		for (int j = 0; j < C; j++, jj++)
			cout << ((ii == A - 1 && jj == B - 1) ? (CD[i][j] == '#' ? '.' : '#') : CD[i][j]);
		for (int j = C-1; j >= 0; j--, jj++)
			cout << ((ii == A - 1 && jj == B - 1) ? (CD[i][j] == '#' ? '.' : '#') : CD[i][j]);
		cout << endl;
	}
	for (int i = R-1; i >= 0; i--, ii++) {
		int jj = 0;
		for (int j = 0; j < C; j++, jj++)
			cout << ((ii == A - 1 && jj == B - 1) ? (CD[i][j] == '#' ? '.' : '#') : CD[i][j]);
		for (int j = C - 1; j >= 0; j--, jj++)
			cout << ((ii == A - 1 && jj == B - 1) ? (CD[i][j] == '#' ? '.' : '#') : CD[i][j]);
		cout << endl;
	}
	return 0;
}