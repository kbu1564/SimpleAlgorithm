#include <iostream>
using namespace std;
int main() {
	int N, K; cin >> N >> K;

	int result = 1;
	for (int i = 1; i <= N; i++) {
		result = (result + K - 1) % i + 1;
	}
	cout << result << endl;
	return 0;
}
