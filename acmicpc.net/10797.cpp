#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;

	int ARR[10] = { 0, };
	for (int i = 0; i < 5; i++) {
		int ni; cin >> ni;
		ARR[ni]++;
	}

	cout << ARR[n] << endl;
	return 0;
}
