#include <cstdio>
#include <iostream>
using namespace std;

char MAP[51][51];
int main() {
	int N; cin >> N;
	char M[51]; cin >> M;
	for (int i = 0; i < 51; i++) for (int j = 0; j < 51; j++) MAP[i][j] = '#';
	int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
	int dist = 2; // top : 0, right : 1, bottom : 2, left : 3
	for (int i = 0; M[i]; i++) {
		if (M[i] == 'R') {
			dist = (dist + 3) % 4;
		}
		if (M[i] == 'L') {
			dist = (dist + 1) % 4;
		}
	}
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) cout << MAP[i][j];
		cout << "\n";
	}
	return 0;
}
