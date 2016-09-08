#include <iostream>
using namespace std;

char S[101];
int main() {
	cin >> S;

	int result = -1;
	while (S[++result]);
	cout << result << endl;
	return 0;
}
