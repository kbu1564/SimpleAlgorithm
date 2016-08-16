#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int DP[1000001];
int main() {
	int N; cin >> N;
	for (int h = 1; h < 10; h++) {
		for (int e = 1; e < 10; e++) {
			for (int l = 1; l < 10; l++) {
				for (int o = 1; o < 10; o++) {
					int n1 = h * 1e4 + e * 1e3 + l * 1e2 + l * 1e1 + o;
					int n2 = N - n1;
					if (n1 >= 1e5 || n2 >= 1e5) continue;
					if (n2 > 0 && n2 / 10000 > 0) {
						if (o == n2 % 10000 / 1000 && l == n2 % 100 / 10) {
							set<int> S;
							S.insert(h); S.insert(e); S.insert(l); S.insert(o);
							S.insert(n2 / 10000);
							S.insert(n2 % 1000 / 100);
							S.insert(n2 % 10);
							if (S.size() < 7) continue;

							cout << "  " << n1 << endl;
							cout << "+ " << n2 << endl;
							cout << "-------" << endl;
							if (N < 1e5) cout << " ";
							cout << " " << N << endl;
							return 0;
						}
					}
				}
			}
		}
	}
	cout << "No Answer" << endl;
	return 0;
}
