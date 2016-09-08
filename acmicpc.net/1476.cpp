#include <iostream>
using namespace std;

int main() {
	int E, S, M; cin >> E >> S >> M;
	int e = 0, s = 0, m = 0;
	int result = 1;
	while (e+1 != E || s+1 != S || m+1 != M) {
		e = (e + 1) % 15;
		s = (s + 1) % 28;
		m = (m + 1) % 19;
		result++;
	}
	cout << result << endl;
	return 0;
}
