#include <iostream>
using namespace std;
int IT[5001];
int sum(int s, int e, int S, int E, int p) {
	if (s > E || e < S) return 0;
	if (s >= S && e <= E) return IT[p];
	return sum(s, (s+e)/2, S, E, p*2) + sum((s+e)/2+1, e, S, E, p*2+1);
}
int main() {
	int N, Q;
	cin >> N >> Q;

	int P = 1;
	while (P < N) P *= 2;

	for (int i = P; i < P + N; i++) {
		cin >> IT[i];
		int curr = i;
		while (curr > 0) {
			IT[curr/2] += IT[i];
			curr /= 2;
		}
	}

	for (int i = 0; i < Q; i++) {
		int S, E;
		cin >> S >> E;
		cout << sum(1, P, S, E, 1) << endl;
	}
	return 0;
}
