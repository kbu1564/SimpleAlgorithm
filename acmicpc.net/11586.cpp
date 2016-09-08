#include <iostream>
using namespace std;
char MIRROR[101][101];
int main() {
	int N; cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> MIRROR[i][j];

	int K; cin >> K;
	switch (K) {
	case 1:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cout << MIRROR[i][j];
			cout << endl;
		}
		break;
	case 2:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cout << MIRROR[i][N-1-j];
			cout << endl;
		}
		break;
	case 3:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cout << MIRROR[N-1-i][j];
			cout << endl;
		}
		break;
	}
	return 0;
}
