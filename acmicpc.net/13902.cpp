#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int ARR[1001];
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &ARR[i]);
	}
	sort(ARR, ARR+M);
	return 0;
}
