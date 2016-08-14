#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int A, B, N;
	cin >> A >> B >> N;
	for (int i = 1; i <= N; i++) {
		cout << A * N + B * i << " ";
	}
	cout << endl;
	return 0;
}
