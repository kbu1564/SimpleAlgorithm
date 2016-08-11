#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int result = 0;
	int curr = 0;
	for (int i = 0; i < 4; i++) {
		int in, out;
		cin >> out >> in;
		curr += in;
		curr -= out;
		result = max(result, curr);
	}
	cout << result << endl;
	return 0;
}