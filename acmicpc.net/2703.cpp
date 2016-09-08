#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T; scanf("%d ", &T);
	for (int tc = 1; tc <= T; tc++) {
		char DE[255] = { 0, };
		char S1[1001] = { 0, }, S2[27] = { 0, };
		gets(S1);
		scanf("%s ", S2);
		for (int i = 0; S2[i]; i++) {
			DE['A' + i] = S2[i];
		}
		for (int i = 0; S1[i]; i++) {
			if (S1[i] == '\n') break;
			cout << (DE[S1[i]] == 0? ' ': DE[S1[i]]);
		}
		cout << endl;
	}
	return 0;
}
