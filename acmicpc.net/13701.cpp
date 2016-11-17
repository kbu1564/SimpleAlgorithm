#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int ARR[1048577];
int main() {
	int N;
	while (~scanf("%d", &N)) {
		if ((ARR[N/32] & (1 << (N % 32))) == 0) {
			printf("%d ", N);
			ARR[N/32] = (ARR[N/32] ^ (1 << (N % 32)));
		}
	}
	printf("\n");
	return 0;
}
