#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> DP;
//int DP[2001];
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int ni; cin >> ni;
		DP[ni]++;
	}

	for (auto& v : DP) {
		cout << v.first << " => " << v.second << endl;
	}
	return 0;
}
