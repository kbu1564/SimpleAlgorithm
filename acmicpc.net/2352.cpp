#include <cstdio>
#include <iostream>
using namespace std;

int DP[40001];
int search(int ARR[], int s, int e, int v) {
	if (s == e) return s;

	int mid = (s + e) / 2;
	if (ARR[mid] > v) return search(ARR, s, mid, v);
	if (ARR[mid] < v) return search(ARR, mid+1, e, v);
	return mid;
}
int main() {
	int result = 0;
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int NI; scanf("%d", &NI);
		int pos = search(DP, 0, result + 1, NI);
		DP[pos] = NI;
		if (result < pos) result = pos;
	}
	printf("%d\n", result);
	return 0;
}
