#include <iostream>
#include <set>
using namespace std;

set<int> S;
int DP[100001];
int main() {
	int N; cin >> N;
	for (int i = 1; i * i <= 100000; i++) {
		DP[i * i] = 1;
		S.insert(i*i);
	}

	for (int i = 1; i <= N; i++) {
		for (set<int>::iterator last = --S.upper_bound(i); last != S.end(); last--) {
			if (DP[i + *last] > DP[i] + DP[*last]) {
				DP[i + *last] = DP[i] + DP[*last];
			}
		}
	}

	cout << DP[N] << endl;
	
	return 0;
}
