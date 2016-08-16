#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N; cin >> N;
	int div = 2;
	while (N > 0 && div <= N) {
		if (N % div == 0) {
			cout << div << endl;
			N /= div;
		} else {
			div++;
		}
	}
	return 0;
}
