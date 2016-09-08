#include <iostream>
using namespace std;
int main() {
	int A, B, C; cin >> A >> B >> C;
	int R[3] = { 0, };
	char S[5] = { 0, };
	cin >> S;

	int tA = A, tB = B, tC = C;;
	A = min(tA, min(tB, tC));
	C = max(tA, max(tB, tC));
	B = tA + tB + tC - A - C;

	for (int i = 0; i < 3; i++) {
		if (S[i] == 'A') R[i] = A;
		if (S[i] == 'B') R[i] = B;
		if (S[i] == 'C') R[i] = C;
		cout << R[i] << " ";
	}
	cout << endl;
	return 0;
}
