#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	int t = 0;
	int r = 1;
	while (N > 0) {
		if (r > N) r = 1;
		N -= r;
		r++;
		t++;
	}
	cout << t << endl;
	return 0;
}
