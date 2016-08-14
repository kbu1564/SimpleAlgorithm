#include <iostream>
#include <algorithm>
using namespace std;

int N;
int COIN[101];
int BC[200001], OR[200001];
int bc(int n) {
	if (n <= 0) return 0;
	if (BC[n] > 0) return BC[n];

	int coin = 0;
	for (int i = N-1; i >= 0; i--) {
		if (COIN[i] <= n) {
			coin = COIN[i];
			break;
		}
	}
	return BC[n] = bc(n - coin) + 1;
}
int main() {
	cin >> N;
	for (int i = 0; i < 200001; i++) OR[i] = 1e9;
	for (int i = 0; i < N; i++) {
		cin >> COIN[i];
		OR[COIN[i]] = BC[COIN[i]] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < 200001; j++) {
			if (j >= COIN[i]) {
				OR[j] = min(OR[j], OR[j-COIN[i]] + 1);
			}
		}
	}

	int isYes = 1;
	for (int j = 1; j < 200001; j++) {
		if (OR[j] < 1e9) {
			if (OR[j] != bc(j)) {
				isYes = 0; break;
			}
		}
	}
	cout << (isYes == 1? "Yes": "No") << endl;
	return 0;
}
