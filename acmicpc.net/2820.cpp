#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int P[500001];
long long M[500001];
long long A[500001];
long long D[500001];
vector<long long> V[500001]; // i의 자식 정보
long long chain(int i) {
	if (D[i] > 0) return D[i];
	long long rst = A[P[i]];
	if (i != P[i] || i > 0) rst += chain(P[i]);
	return D[i] = rst;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%lld", &M[1]);
	for (int i = 2; i <= n; i++) {
		int money, parent;
		scanf("%d %d", &money, &parent);
		V[parent].push_back(i);
		P[i] = parent;
		M[i] = money;
	}
	for (int i = 1; i <= m; i++) {
		char cmd[2];
		int a, x;
		scanf("%s", cmd);
		if (cmd[0] == 'p') {
			scanf("%d %d", &a, &x);
			A[a] += x;

            /*
			queue<int> Q;
			Q.push(a);
			while (!Q.empty()) {
				int curr = Q.front(); Q.pop();
				if (curr == 1) break;
				for (auto v : V[curr]) {
					D[v] += x;
					Q.push(v);
				}
			}
            */
		}
		if (cmd[0] == 'u') {
			scanf("%d", &a);
            long long money = M[a];
            int curr = P[a];
            while (curr > 0) {
                money += A[curr];
                curr = P[curr];
            }
			printf("%lld\n", money);
		} 
	}
	return 0;
}

