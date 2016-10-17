#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int IN[10001];
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int w; scanf("%d", &w);
		IN[w]++;
	}

	int totalCount = 0;
	int result = 0;
	for (int i = 10000; i >= 1; i--) {
		totalCount += IN[i];
		result = max(result, i * totalCount);
	}
	printf("%d\n", result);
	return 0;
}
