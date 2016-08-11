#include <cstdio>
#include <iostream>
using namespace std;
struct point {
	long long s, e;
};
long long N, K, Q;
const int SIZE = 10000;
point P[SIZE];
int main() {
	cin >> N >> K >> Q;
	long long snode = 1, enode = 1, count = 1;
	for (int i = 0; count <= N; i++) {
		P[i] = (point){ snode, enode };
		count = count * K;
		snode = enode + 1;
		enode = snode + count - 1;
	}

	for (int i = 0; i < Q; i++) {
		long long S, E; scanf("%lld %lld", &S, &E);
		int sdepth = 0;
		for (int j = 0; j < SIZE; j++) {
			if (P[j].s <= S && P[j].e >= S) {
				break;
			}
			sdepth++;
		}

		int edepth = 0;
		for (int j = 0; j < SIZE; j++) {
			if (P[j].s <= E && P[j].e >= E) {
				break;
			}
			edepth++;
		}
		printf("%d\n", sdepth + edepth);
	}
	return 0;
}
