#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int N; cin >> N;
		int DOORS[101] = { 0, };
		for (int j = 1; j <= N; j++) {
			int curr = j;
			while (curr <= N) {
				DOORS[curr] ^= 1;
				curr += j;
			}
		}

		int result = 0;
		for (int j = 1; j <= N; j++)
			if (DOORS[j] == 1)
				result++;

		cout << result << endl;
	}
	return 0;
}
