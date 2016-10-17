#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int ARR[1000001];
int main() {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) cin >> ARR[i];
	sort(ARR+1, ARR+N+1);

	int result = -1;
	for (int i = N; i > 0; i--) {
		if (i < 2) break;
		if (ARR[i] < ARR[i-1] + ARR[i-2]) {
			result = max(result, ARR[i] + ARR[i-1] + ARR[i-2]);
			break;
		}
	}
	printf("%d\n", result);
	return 0;
}
