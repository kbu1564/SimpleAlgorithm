#include <iostream>
using namespace std;
int BEAT[201];
int main() {
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;

	int turn = 0;
	int count = 0;
	int beat = m;
	while (count < N) {
		if (beat + T <= M) {
			beat += T;
			count++;
		} else {
			beat -= R;
			if (BEAT[beat] == count) {
				turn = -1; break;
			}
			BEAT[beat] = count;
		}
		if (beat < m) beat = m;
		turn++;
	}
	cout << turn << endl;
	return 0;
}
