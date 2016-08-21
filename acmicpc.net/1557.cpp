#include <iostream>
using namespace std;

int main() {
	int K; cin >> K;
	int i = K;
	for (; K > 0; i++) {
		K--;
		for (int j = 2; j * j <= i; j++) {
			if (i % (j*j) == 0) {
				K++; break;
			}
		}
	}
	cout << i-1 << endl;
	return 0;
}
