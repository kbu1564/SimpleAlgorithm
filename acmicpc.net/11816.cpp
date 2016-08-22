#include <iostream>
using namespace std;
int main() {
	char S[10]; cin >> S;

	int result = 0;
	if (S[0] == '0' && S[1] != 'x') {
		for (int i = 1; S[i]; i++) result = result * 8 + (S[i] - '0');
	}
	if (S[0] == '0' && S[1] == 'x') {
		for (int i = 2; S[i]; i++) {
			int num = 0;
			if (S[i] >= '0' && S[i] <= '9') {
				num = S[i] - '0';
			} else {
				num = (S[i] - 'a') + 10;
			}
			result = result * 16 + num;
		}
	}
	if (S[0] != '0') {
		for (int i = 0; S[i]; i++) result = result * 10 + (S[i] - '0');
	}
	cout << result << endl;
	return 0;
}
