#include <iostream>
using namespace std;
int main() {
	char N1[10], N2[10];
	cin >> N1 >> N2;

	long long n1 = 0;
	for (int i = 0; N1[i]; i++) n1 = n1 * 10 + (N1[i] - '0');
	for (int i = 0; N2[i]; i++) n1 = n1 * 10 + (N2[i] - '0');

	cin >> N1 >> N2;
	long long n2 = 0;
	for (int i = 0; N1[i]; i++) n2 = n2 * 10 + (N1[i] - '0');
	for (int i = 0; N2[i]; i++) n2 = n2 * 10 + (N2[i] - '0');

	cout << n1 + n2 << endl;
	return 0;
}

