#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int nA, nB;
int A[500001];
int B[500001];
bool binary_search(int s, int e, int v) {
	if (s == e) return B[s] == v;

	int mid = (s + e) / 2;
	if (B[mid] > v) return binary_search(s, mid, v);
	if (B[mid] < v) return binary_search(mid+1, e, v);
	return B[mid] == v;
}

int size = 0;
int ANS[500001];
int main() {
	scanf("%d %d", &nA, &nB);
	for (int i = 0; i < nA; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < nB; i++) {
		scanf("%d", &B[i]);
	}
	sort(A, A+nA);
	sort(B, B+nB);

	for (int i = 0; i < nA; i++) if (binary_search(0, nB-1, A[i]) == true) size++;

	printf("%d\n", nA + nB - 2 * size);
	return 0;
}
