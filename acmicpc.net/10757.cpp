#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	string n1, n2;
	cin >> n1 >> n2;
	string lr = "";
	int lup = 0;
	int mx = max(n1.length(), n2.length());
	for (int j = 0; j < mx; j++) {
		int r = (j < n1.length() ? n1[n1.length() - 1 - j] - '0' : 0) + (j < n2.length() ? n2[n2.length() - 1 - j] - '0' : 0) + lup;
		lup = r / 10;
		r = r % 10;
		lr = (char)(r + '0') + lr;
	}

	if (lup > 0) lr = (char)(lup + '0') + lr;
	n1 = lr;

	cout << n1 << endl;
	return 0;
}
