#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
int main() {
	map<int, int> mp;
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int NI; scanf("%d", &NI);
		mp[NI]++;
	}

	int M; scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int MI; scanf("%d", &MI);
		if (mp.find(MI) == mp.end()) cout << 0 << " ";
		else cout << mp[MI] << " ";
	}
	cout << "\n";
	return 0;
}
