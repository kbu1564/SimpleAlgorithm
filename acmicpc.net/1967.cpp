#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int L[10001]; // L[i] = i노드가 leaf node 라면 0 아니면 1
int P[10001]; // P[i] = i노드의 부모노드
int W[10001]; // W[i] = i노드의 부모와의 가중치
int M[10001]; // M[i] = i의 자식중 leaf node 까지의 경로중 최대값
vector<int> CL[10001]; // CL[i] = i노드의 child nodes
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		CL[u].push_back(v);
		P[v] = u;
		W[v] = w;
		L[u] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (L[i] == 0) {
			int weight = 0;
			int curr = i;
			while (P[curr] != 0) {
				weight = weight + W[curr];
				M[P[curr]] = max(M[P[curr]], weight);
				curr = P[curr];
			}
		}
	}

	int result = 0;
	queue<int> Q;
	Q.push(1);
	while (!Q.empty()) {
		int r = Q.front(); Q.pop();
		if (CL[r].size() == 0) continue;

		priority_queue<int> PQ;
		for (auto& v : CL[r]) {
			PQ.push(W[v] + M[v]);
			Q.push(v);
		}

		if (PQ.size() <= 1) {
			int p1 = PQ.top(); PQ.pop();
			result = max(result, p1);
		} else {
			int p1 = PQ.top(); PQ.pop();
			int p2 = PQ.top(); PQ.pop();
			result = max(result, p1 + p2);
		}
	}
	printf("%d\n", result);
	return 0;
}

