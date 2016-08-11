#include <iostream>
using namespace std;
const int SIZE = 201;
char MAP[SIZE][SIZE];
int main() {
	int N, M, K;
	cin >> N >> M >> K;

	int nN = 2 * N + 1;, nM = 2 * M + 1;
	for (int i = 0; i < nM; i++) for (int j = 0; j < nN; j++) cin >> M[i][j];
	return 0;
}
