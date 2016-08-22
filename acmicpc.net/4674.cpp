#include <iostream>
using namespace std;
int len(char str[]) {
	int result = 0;
	while (str[result]) result++;
	return result;
}

int PLAINTEXT[255];
char PLAINCODE[28];
int main() {
	PLAINTEXT['_'] = 0;  PLAINCODE[0] = '_';
	PLAINTEXT['.'] = 27; PLAINCODE[27] = '.';
	for (int i = 'a'; i <= 'z'; i++) {
		PLAINTEXT[i] = (i-'a')+1;
		PLAINCODE[(i-'a')+1] = i;
	}

	while (1) {
		int K; cin >> K;
		if (K == 0) break;

		char ENC[71] = { 0, };
		char DEC[71] = { 0, };
		cin >> ENC;

		int N = len(ENC);
		for (int i = 0; ENC[i]; i++) {
			int cipherCode = PLAINTEXT[ENC[i]];
			//cout << K * i % N << " " << cipherCode << endl;
			DEC[K * i % N] = PLAINCODE[(cipherCode + i) % 28];
		}
		cout << DEC << endl;
	}
	return 0;
}
