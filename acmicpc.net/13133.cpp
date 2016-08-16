#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
struct family {
	int father, mother;
};

int HAPPY[501];
family DP[501];
int main() {
	ios::sync_with_stdio(false);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> DP[i].father >> DP[i].mother;
		if (DP[i].father > 0 && DP[i].mother > 0) {
			HAPPY[i] = 1;
		}
	}

	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int none; cin >> none;

		HAPPY[none] = 0;
		for (int j = 1; j <= N; j++) {
			if (DP[j].father > 0 && DP[j].mother > 0) {
				if (DP[j].father == none || DP[j].mother == none) {
					HAPPY[j] = 0;
				}
			}	
		}
	}

	int result = 0;
	for (int i = 1; i <= N; i++) result += HAPPY[i];
	cout << result << endl;
	return 0;
}
