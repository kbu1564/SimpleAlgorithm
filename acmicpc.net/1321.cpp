#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int CC[1100001];
int NC[1100001];
int find(int s, int e, int S, int E, int p) {
	if (s > E || e < S) return 0;
	if (s >= S && e <= E) return NC[p];
	return find(s, (s+e)/2, S, E, p*2) + find((s+e)/2+1, e, S, E, p*2+1);
}
