#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> in, dec, inc;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string S; cin >> S;
		in.push_back(S);

		dec.push_back(S);
		inc.push_back(S);
	}

	sort(inc.begin(), inc.end());
	sort(dec.begin(), dec.end(), greater<string>());

	bool isInc = true;
	bool isDec = true;
	for (int i = 0; i < N; i++) if (in[i] != inc[i]) isInc = false;
	for (int i = 0; i < N; i++) if (in[i] != dec[i]) isDec = false;

	if (isInc) cout << "INCREASING" << endl;
	else if (isDec) cout << "DECREASING" << endl;
	else if (!isInc && !isDec) cout << "NEITHER" << endl;

	return 0;
}
