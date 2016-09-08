#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int nA, nB;
long long A[500001];
long long B[500001];
bool binary_search(int s, int e, long long v) {
	if (s == e) return B[s] == v;

	int mid = (s + e) / 2;
	if (B[mid] > v) return binary_search(s, mid, v);
	if (B[mid] < v) return binary_search(mid+1, e, v);
	return B[mid] == v;
}

int size = 0;
long long ANS[500001];
int main() {
	scanf("%d %d", &nA, &nB);
	for (int i = 0; i < nA; i++) {
		scanf("%lld", &A[i]);
	}
	for (int i = 0; i < nB; i++) {
		scanf("%lld", &B[i]);
	}
	sort(A, A+nA);
	sort(B, B+nB);

	for (int i = 0; i < nA; i++) {
		if (binary_search(0, nB-1, A[i]) == false) {
			ANS[size++] = A[i];
		}
	}

	printf("%d\n", size);
	for (int i = 0; i < size; i++) {
		printf("%lld ", ANS[i]);
	}
	if (size > 0) printf("\n");
	return 0;
}
