#include <iostream>
#include <cstring>
using namespace std;
int N, K;
int KNOWN[256];
int STRC[256];
char STR[51][20];
int main() {
	// 최대 공통 부분 수열 구하는 문제를 변형하면 풀수 있을 것 같음!!
	// anta ~ tica로 시작하고 끝나므로 무조건 아래 단어를 알아야 한다.
	KNOWN['a'] = KNOWN['n'] = KNOWN['t'] = KNOWN['i'] = KNOWN['c'] = 1;

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> STR[i];
	for (int i = 0; i < N; i++) {
		int l = strlen(STR[i]);
		int C[256] = { 0, };
		for (int j = 0; j < l; j++) C[STR[i][j]]++;

		int cnt = 0;
		for (int j = 0; j < 256; j++) {
			if (C[j] > 0) {
				STRC[j]++;
				cnt++;
			}
		}
		cout << STR[i] << " : " << cnt << endl;
	}

	for (int j = 0; j < 256; j++) {
		if (STRC[j] > 0) {
			cout << (char)j << " : " << STRC[j] << endl;
		}
	}
	return 0;
}
