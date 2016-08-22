#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int R; cin >> R;

	int NX[26] = { 0, };
	int BA[26] = { 0, };
	for (int i = 1; i <= R; i++) {
		int IN[26] = { 0, };
		for (int j = 0; j < i; j++) {
			cin >> IN[j];
			NX[j] = max(BA[j-1], BA[j]) + IN[j];
		}
		for (int j = 0; j < i; j++) BA[j] = NX[j];
	}

	int result = 0;
	for (int i = 0; i < R; i++) {
		result = max(result, BA[i]);
	}

	cout << result << endl;
	return 0;
}
