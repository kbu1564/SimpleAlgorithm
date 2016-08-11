#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int VISIT[100001];
vector<int> v[100001];
void dfs(int node) {
	if (VISIT[node] == 1) return;
	printf("%d ", node);

	vector<int> vec = v[node];
	vector<int> temp;
	VISIT[node] = 1;
	int veclen = vec.size();
	for (int i = 0; i < veclen; i++) {
		if (VISIT[vec[i]] == 0){
			temp.push_back(vec[i]);
		}
	}

	int templen = temp.size();
	for (int i = 0; i < templen; i++) {
		if (templen > 0) {
			if (templen % 2 == 0)
				dfs(temp[0]);
			else
				dfs(temp[templen/2]);
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].size() <= 0) continue;
		sort(v[i].begin(), v[i].end());
	}
	dfs(1);
	printf("\n");
	return 0;
}

