#include <iostream>
using namespace std;
int main() {
	int N; cin >> N;
	int rst = 0;
	for (int i = 0; i <= 32 && N > 0; i++) {
		rst = (rst << 1) + (N & 1);
		N >>= 1;
	}
	cout << rst << endl;
	return 0;
}
