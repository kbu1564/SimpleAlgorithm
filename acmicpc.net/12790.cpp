#include <iostream>
using namespace std;
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int hp, mp, at, df, ahp, amp, aat, adf;
		cin >> hp >> mp >> at >> df >> ahp >> amp >> aat >> adf;

		hp += ahp; mp += amp; at += aat; df += adf;
		if (hp < 1) hp = 1;
		if (mp < 1) mp = 1;
		if (at < 0) at = 0;
		cout << hp + 5*mp + 2*at + 2*df << endl;
	}
	return 0;
}
