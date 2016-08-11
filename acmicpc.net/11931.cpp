#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int MRR[1000001];
int ARR[1000001];
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int v; scanf("%d", &v);
		if (v >= 0) ARR[v] = 1;
		else MRR[abs(v)] = 1;
	}
	
	for (int i = 1000000; i >= 0; i--) if (ARR[i] == 1) printf("%d\n", i);
	for (int i = 1; i < 1000001; i++)  if (MRR[i] == 1) printf("%d\n", -i);

	return 0;
}
