#include <string>
#include <iostream>
using namespace std;
char S[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main() {
	string str;
	char w = 0;
	while (~(w = getchar())) {
		int idx = 0;
		for (idx = 0; S[idx] && S[idx] != w; idx++);
		if (S[idx]) cout << S[idx-1];
		else cout << w;
	}
	return 0;
}
