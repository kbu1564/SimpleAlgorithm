#include <cstdio>
#include <iostream>
using namespace std;

bool PR[5001];
int main() {
	for (int i = 2; i * i < 5001; i++)
		for (int j = 2; j * i < 5001; j++)
			PR[j*i] = true;

	char S[21];
	cin >> S;

	int sum = 0;
	for (int i = 0; S[i]; i++) {
		if (S[i] >= 'a' && S[i] <= 'z') sum += S[i] - 'a' + 1;
		if (S[i] >= 'A' && S[i] <= 'Z') sum += (S[i] - 'A') + 27;
	}

	cout << (PR[sum] == true? "It is not a prime word.": "It is a prime word.") << endl;
	return 0;
}
