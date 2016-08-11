#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int N;
	while (cin >> N) {
		int DP[6001] = { 0, }, ARR[3001] = { 0, };
		for (int i = 0; i < N; i++) {
			cin >> ARR[i];
			if (i > 0) {
				DP[abs(ARR[i]-ARR[i-1])]++;
			}
		}
		string result = "Jolly";
		for (int i = 1; i < N; i++) {
			if (DP[i] <= 0) {
				result = "Not jolly";
				break;
			}
		}
		cout << result << endl;
	}
	return 0;
}
