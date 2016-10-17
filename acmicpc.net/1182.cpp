#include <iostream>
using namespace std;

int DP[2000001];
int ARR[21];
int main() {
	int N, S; cin >> N >> S;

	DP[1000000] = 1;
	for (int i = 0; i < N; i++) {
		cin >> ARR[i]; ARR[i] += 100000;
		for (int j = 2000000; j >= ARR[i]; j--) {
			DP[j] += DP[j-ARR[i]];
		}
	}
	for (int j = 0; j < 100000; j++) cout << DP[j] << " ";
	cout << DP[S] << endl;
	return 0;
}
