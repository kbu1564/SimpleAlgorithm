#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int MAP[501][501];
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &MAP[i][j]);
		}
	}
	return 0;
}
