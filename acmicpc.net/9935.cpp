#include <iostream>
#include <string.h>
using namespace std;

char STR1[1000001];
char STR2[40];
char S[1000001];
int t;
int main() {
  cin >> STR1 >> STR2;

  int l1 = strlen(STR1), l2 = strlen(STR2);
	for (int i = 0; i < l1; i++) {
		S[t++] = STR1[i];

		int curr = l2;
		for (int j = 1; j <= l2 && S[t-j] == STR2[curr-1]; j++) curr--;

		if (curr == 0) {
			// pop
			for (int j = l2-1; S[t-1] == STR2[j] && j >= 0; j--) --t;
		}
	}
	S[t] = 0;
	cout << (t > 0? S: "FRULA") << endl;

  return 0;
}

