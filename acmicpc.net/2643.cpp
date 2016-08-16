#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int, int> S[1000];
int main() {
	int N; cin >> N;
	vector< pair<int, int> > P;
	for (int i = 0; i < N; i++) {
		int w1, w2; cin >> w1 >> w2;
		P.push_back(pair<int, int>(min(w1, w2), max(w1, w2)));
	}

	sort(P.begin(), P.end());

	int t = 0;
	for (auto p = P.rbegin(); p != P.rend(); p++) {
		if (t == 0) S[t++] = pair<int, int>(p->first, p->second);

		pair<int, int> data = S[t-1];
		if (p->second <= data.second) {
			S[t++] = pair<int, int>(p->first, p->second);
		}
	}

	int c = 0;
	for (int i = t - 1; i > 0; i--) {
		pair<int, int> p = S[i];
		c++;
		//cout << "? : " << p.first << " " << p.second << endl;
	}
	cout << c << endl;
	return 0;
}
