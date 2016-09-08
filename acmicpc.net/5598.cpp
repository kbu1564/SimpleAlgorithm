#include <iostream>
using namespace std;
int main() {
	string ENC; cin >> ENC;
	for (int i = 0; i < ENC.length(); i++) {
		cout << (char)('A'+((ENC[i]-'A'+26-3)%26));
	}
	cout << endl;
	return 0;
}
