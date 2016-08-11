#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int opidx = 0;
	char OP[51] = { 0, };

	int nidx = 0;
	int N[51] = { 0, };

	int plusCount = 0;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == '+' || str[i] == '-') {
			if (str[i] == '+') plusCount++;
			OP[opidx++] = str[i];
			nidx++;
			continue;
		}
		N[nidx] = N[nidx] * 10 + (str[i] - '0');
	}

	while (plusCount > 0) {
		plusCount = 0;
		for (int i = 0; i <= opidx; i++) {
			if (OP[i] == '+') {
				N[i+1] = N[i] + N[i+1];
				N[i] = -1;
				OP[i] = ' ';
				plusCount++;
			}
		}
	}

	int rst = 0;
	int opcurr = 0;
	// 50 + 40 - 30 + 20
	for (int i = 0; i <= nidx; i++) {
		while (OP[opcurr] == ' ') opcurr++;
		if (N[i] < 0) continue;

		if (i > 0) {
			if (OP[opcurr] == '-') {
				rst = rst - N[i];
			}
		} else {
			rst = N[i];
		}
	}
	cout << rst << endl;

	return 0;
}
