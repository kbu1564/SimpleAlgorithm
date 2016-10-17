#include <iostream>
using namespace std;
int main() {
	int N; cin >> N;

	long long n1 = 1, n2 = 1;
	long long l1 = 1, l2 = 1;
	for (int i = 1; i <= N; i++) {
		l1 = l2;
		l2 = n2;

		long long t1 = n2;
		n2 = n1 + n2;
		n1 = t1;
	}

	cout << l1*2 + l2*2 << endl;
	return 0;
}
