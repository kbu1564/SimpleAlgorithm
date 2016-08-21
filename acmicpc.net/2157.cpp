#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int MAP[301][301];
int main() {
	int N, M, K; scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		MAP[a][b] = c;
	}
	return 0;
}
