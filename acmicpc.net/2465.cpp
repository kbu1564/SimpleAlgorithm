#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, NI;
int IT[210001];
int S[100001];
vector<int> A;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &NI);
		A.push_back(NI);
	}
	for (int i = 0; i < N; i++) scanf("%d", &S[i]);
	sort(A.begin(), A.end());

	int P = 1;
	while (P < N) P *= 2;

	for (int i = N-1; i >= 0; i--) {
		int idx = 0;
		for (auto j : A) {
			if (idx == S[i]) break;
			idx++;
		}
		// 0 ~ idx 까지의 부분합
		cout << A[idx] << "(" << idx << ") ";

		IT[P + idx]++;
		int curr = P + idx;
		while (curr > 0) {
			IT[curr/2]++;
			curr /= 2;
		}
	}
	cout << endl;
	return 0;
}

