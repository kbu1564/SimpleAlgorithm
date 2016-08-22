#include <iostream>
using namespace std;
int main() {
	while (1) {
		int N; cin >> N;
		if (N == 0) break;

		char MAP[5][5] = { 0, };
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> MAP[i][j];
	}
	return 0;
}
