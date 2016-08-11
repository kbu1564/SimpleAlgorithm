#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
struct score {
	int s, e;
	bool operator<(const score& sc) const {
		return (e - s + 1) < (sc.e - sc.s + 1);
	}
};

char M[200001];
int main() {
	ios::sync_with_stdio(false);

	int N, Q; scanf("%d %d", &N, &Q);
	for (int i = 1; i <= Q; i++) {
		int qi; scanf("%d", &qi);
		M[qi] = ~M[qi];

		int lsc = 0, rsc = 0;
		for (int j = qi-1; j >= 1; j--) if (M[j] == ~M[j+1]) lsc++; else break;
		for (int j = qi+1; j <= N; j++) if (M[j] == ~M[j-1]) rsc++; else break;
		int scr = lsc + rsc + 1;
	}
	return 0;
}
