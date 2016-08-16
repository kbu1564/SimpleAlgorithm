#include <iostream>
#include <queue>
using namespace std;
enum { U, D, L, R };
struct point {
	int x, y, d, k, c;
	char candy;
};
char M[51][51];
int AX[4] = { 0, 0, -1, 1 }, AY[4] = { -1, 1, 0, 0 };
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> M[i][j];

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int count = 0;
				int nx = j;
				int ny = i;
				char ncandy = M[ny][nx];
				char candy = M[i][j];
				while (ncandy == candy) {
					nx += AX[k];
					ny += AY[k];
					ncandy = M[ny][nx];
					count++;
				}

