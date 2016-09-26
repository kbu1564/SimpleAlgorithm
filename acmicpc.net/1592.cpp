#include <iostream>
using namespace std;

int ARR[1001];
int main() {
	int N, M, L; cin >> N >> M >> L;
	int result = 0;
	int curr = 0;
	while ((++ARR[curr]) < M) {
		cout << curr+1 << " ";
		if (ARR[curr] % 2 == 1) curr = (curr + N - L) % N;
		else if (ARR[curr] % 2 == 0) curr = (curr + L) % N;
		result++;
	}
	cout << endl;
	cout << result << endl;
	return 0;
}
