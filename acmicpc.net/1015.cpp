#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int P[1001];
int main() {
	int N; cin >> N;
	vector< pair<int, int> > vec;
	for (int i = 0; i < 1001; i++) P[i] = -1;
	for (int i = 0; i < N; i++) {
		int ni; cin >> ni;
		vec.push_back(pair<int, int>(ni, i));
	}
	sort(vec.begin(), vec.end());

	int veclen = vec.size();
	for (int i = 0; i < veclen; i++) {
		P[vec[i].second] = i;
	}
	for (int i = 0; i < 1001; i++) {
		if (P[i] < 0) continue;
		cout << P[i] << " ";
	}
	cout << endl;
	return 0;
}
