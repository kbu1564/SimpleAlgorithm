#include <iostream>
using namespace std;
int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n1, n2, n3; char op1, op2;
		cin >> n1 >> op1 >> n2 >> op2 >> n3;
		bool rst = false;
		if (op1 == '+') rst = (n3 == n1 + n2);
		if (op1 == '-') rst = (n3 == n1 - n2);

		cout << "Case " << tc << ": " << (rst == true? "Yes": "No") << endl;
	}
	return 0;
}
