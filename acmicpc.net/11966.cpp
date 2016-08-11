#include <iostream>
using namespace std;
int main() {
	int N; cin >> N;
	int rst = 0;
	for (int i = 0; i <= 32; i++) {
		if ((N & (1 << i)) == N) {
			rst = 1;
			break;
		}
	}
	cout << rst << endl;
	return 0;
}
