#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s; cin >> s;

	vector<string> v;
	int slen = s.length();
	for (int i = 0; i < slen; i++) {
		const char* si = s.c_str() + i;
		v.push_back(si);
	}
	sort(v.begin(), v.end());

	for (auto i : v) {
		cout << i << endl;
	}
	return 0;
}
