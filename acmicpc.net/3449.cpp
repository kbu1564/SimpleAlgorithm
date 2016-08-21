#include <iostream>
using namespace std;
int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		char S1[101], S2[101]; cin >> S1 >> S2;

		int result = 0;
		for (int j = 0; S1[j] != 0; j++) if (S1[j] != S2[j]) result++;
		cout << "Hamming distance is " << result << "." << endl;
	}
	return 0;
}
