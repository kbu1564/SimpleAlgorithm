#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;
	reverse(s.begin(), s.end());

	string result;
	for (int i = 0; i < s.length(); i+=3) {
		int num = 0;
		for (int j = 0; j < 3; j++) {
			if (i+j >= s.length()) break;
			num += (s[i+j]-'0') << j;
		}
		result = (char)(num + '0') + result;
	}

	cout << result << endl;
	return 0;
}
