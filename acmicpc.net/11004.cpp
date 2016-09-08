#include <cstdio>

int N, K;
int ARR[5000001];
int binary_search(int s, int e, int v) {
	if (s == e) return s;

	int mid = (s + e) / 2;
	if (ARR[mid] > v) return binary_search(s, mid, v);
	if (ARR[mid] < v) return binary_search(mid+1, e, v);
	return mid;
}

int main() {
	scanf("%d %d", &N, &K);

	int maxIndex = 0;
	for (int i = 0; i < N; i++) {
		int ni; scanf("%d", &ni);

		int pos = binary_search(0, maxIndex + 1, ni);
		ARR[pos] = ni;
		if (maxIndex < pos) maxIndex = pos;
	}

	printf("%d\n", ARR[K-1]);
	return 0;
}
