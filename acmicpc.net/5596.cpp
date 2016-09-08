#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int S = 0;
	for (int j = 0; j < 2; j++) {
		int T = 0;
		for (int i = 0; i < 4; i++) {
			int n; cin >> n;
			T += n;
		}
		S = max(S, T);
	}
	cout << S << endl;
	return 0;
}
