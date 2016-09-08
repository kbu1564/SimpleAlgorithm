#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N; cin >> N;
	int ARR[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	do {
		for (int i = 0; i < N; i++)
			printf("%d ", ARR[i]);
		printf("\n");
	} while (next_permutation(ARR, ARR+N));
	return 0;
}
