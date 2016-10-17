#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct node {
	int n, c;
};

set<int> MAP[10001];
set<int> GRA[10001];
set<int> ANS[10001];
int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int A, B; scanf("%d %d", &A, &B);
		MAP[B].insert(A);
		GRA[A].insert(B);
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (MAP[i].size() <= 0) {
			// leaf 부터 시작
			cout << i << endl;
			queue<node> Q;
			Q.push({ i, 1 });
			while (!Q.empty()) {
				node data = Q.front(); Q.pop();
				for (auto e : GRA[data.n]) {
					Q.push({ e,  });
				}
			}
		}
	}
	return 0;
}
