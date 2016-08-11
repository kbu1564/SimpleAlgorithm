#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int N, NI, M = 1e9;
int main() {
	scanf("%d", &N);

	// max heap
	priority_queue< int, vector<int>, less<int> > Q1;
	// min heap
	priority_queue< int, vector<int>, greater<int> > Q2;
	for (int i = 0; i < N; i++) {
		scanf("%d", &NI);
		if (i == 0)
			M = NI;
		else {
			Q1.push(M);
			Q1.push(NI);
			Q2.push(Q1.top()); Q1.pop();

			if (Q2.size() > Q1.size()) {
				M = Q2.top(); Q2.pop();
			} else {
				M = Q1.top(); Q1.pop();
			}
		}
		printf("%d\n", M);
	}
	return 0;
}
