#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char S[10001];
bool solve(int s, int e) {
	if (s > e) return S[s] == S[e];
	if (S[s] == S[e]) return solve(s + 1, e - 1);
	return false;
}

char c;
int main() {
	int N; cin >> N; getchar();
	for (int i = 0; i < N; i++) {
		gets(S);
		int len = strlen(S);

		cout << S << endl;
		for (int j = 0; j < len; j++) if (S[j] >= 'A' && S[j] <= 'Z') S[j] = 'a' + (S[j]-'A');
		cout << (solve(0, len-1)? "Yes": "No") << endl;
	}
	return 0;
}
