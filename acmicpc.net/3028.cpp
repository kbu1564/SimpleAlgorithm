#include <iostream>
using namespace std;

inline void _swap(int& a, int& b) { int t = a; a = b; b = t; }

int main() {
	char S[51] = { 0, };
	cin >> S;

	int ARR[3] = { 1, 0, 0 };
	for (int i = 0; S[i]; i++) {
		if (S[i] == 'A') _swap(ARR[0], ARR[1]);
		if (S[i] == 'B') _swap(ARR[1], ARR[2]);
		if (S[i] == 'C') _swap(ARR[0], ARR[2]);
	}

	if (ARR[0]) cout << 1 << endl;
	if (ARR[1]) cout << 2 << endl;
	if (ARR[2]) cout << 3 << endl;
	return 0;
}
