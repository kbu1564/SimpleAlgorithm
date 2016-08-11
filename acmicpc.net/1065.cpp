#include <cmath>
#include <iostream>
using namespace std;

int DP[1001];
int main() {
	int N; cin >> N;
	for (int i = 1; i < 1001; i++) {
		if (i < 100)
			DP[i] = 1;
		else {
			int isOneNumber = 1;
			int curr = i / 10;
			int before = i % 10;
			int delta = i % 10 - (i / 10 % 10);
			while (curr > 0) {
				if (delta != before - curr % 10) {
					isOneNumber = 0;
					break;
				}
				delta = before - curr % 10;
				before = curr % 10;
				curr /= 10;
			}
			DP[i] = isOneNumber;
		}
	}

	int result = 0;
	for (int i = 0; i <= N; i++) result += DP[i];
	cout << result << endl;
	return 0;
}
