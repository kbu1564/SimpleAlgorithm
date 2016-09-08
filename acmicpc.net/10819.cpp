#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int result = 0;
int N;
int ARR[8];
void solve(int arr[], int vis[], int size) {
	if (size < 0) {
		int total = 0;
		for (int i = 0; i < N-1; i++)
			total += abs(arr[i] - arr[i+1]);

		result = max(result, total);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (vis[i] == 1) continue;

		vis[i] = 1;
		arr[size] = ARR[i];
		solve(arr, vis, size-1);
		vis[i] = 0;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> ARR[i];
	}

	int DFS[8] = { 0, };
	int VIS[8] = { 0, };
	solve(DFS, VIS, N-1);

	cout << result << endl;
	return 0;
}
