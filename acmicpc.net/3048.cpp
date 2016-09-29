#include <iostream>
using namespace std;

int T;
int N1, N2;
char S1[160], S2[160];
char RST[320];
int main() {
	cin >> N1 >> N2;
	char S[27] = { 0, };

	int j = 0;
	for (int i = 0; i < N1; i++, S[i] = 0) cin >> S[i];
	for (int i = N1-1; i >= 0; i--, j+=2)
		S1[j] = S[i];

	for (int i = 0; i < N2; i++, S[i] = 0) cin >> S[i];

	if (j == 0) j = 1;
	for (int i = 0; S[i]; i++, j+=2)
		S2[j-1] = S[i];

	cin >> T;

	for (int i = 0, k = 0; k < N1; i++) if (S1[i] != 0) {
		RST[i+T*2] = S1[i];
		k++;
	}
	for (int i = 0, k = 0; k < N2; i++) if (S2[i] != 0) {
		RST[i] = S2[i];
		k++;
	}

	int k = 0;
	for (int i = 0; k < N1 + N2; i++) {
		if (RST[i] != 0) {
			cout << RST[i];
			k++;
		}
	}
	cout << endl;
	return 0;
}

