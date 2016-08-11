#include <iostream>
#include <cstring>
using namespace std;
char A[10], B[10];
int main() {
	cin >> A >> B;
	int Alen = strlen(A);
	int Blen = strlen(B);
	int minA = 0, maxA = 0;
	int minB = 0, maxB = 0;
	for (int i = 0; i < Alen; i++) {
		minA = minA * 10 + (A[i] == '6'? 5: A[i]-'0');
		maxA = maxA * 10 + (A[i] == '5'? 6: A[i]-'0');
	}
	for (int i = 0; i < Blen; i++) {
		minB = minB * 10 + (B[i] == '6'? 5: B[i]-'0');
		maxB = maxB * 10 + (B[i] == '5'? 6: B[i]-'0');
	}

	cout << minA + minB << " " << maxA + maxB << endl;
	return 0;
}
