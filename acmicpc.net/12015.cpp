#include <cstdio>

int ARR[1000001];
int DP[1000001];
int binary_search(int ARR[], int s, int e, int v) {
	if (s == e) return s;

	int mid = (s + e) / 2;
	if (ARR[mid] > v) return binary_search(ARR, s, mid, v);
	if (ARR[mid] < v) return binary_search(ARR, mid+1, e, v);
	return mid;
}
int main() {
	int N; scanf("%d", &N);

	int maxLength = 0;
	DP[0] = -1e9;
	for (int i = 0; i < N; i++) {
		scanf("%d", &ARR[i]);
		int pos = binary_search(DP, 0, maxLength + 1, ARR[i]);
		DP[pos] = ARR[i];
		if (maxLength < pos) maxLength = pos;
	}
	printf("%d\n", maxLength);
	return 0;
}
