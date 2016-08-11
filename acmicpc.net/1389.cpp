#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct user { int u, c; };
const unsigned int INF = 987654321;
int ARR[101][101];
user S[10001] = { 0, };
int main() {
	int N, M;
	vector< pair<int, int> > vec;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u1, u2; cin >> u1 >> u2;
		ARR[u1][u2] = ARR[u2][u1] = 1;
	}
	for (int i = 1; i <= N; i++) {
		unsigned int U[101] = { 0, };
        memset(U, INF, sizeof(U));
		int t = 0;
		S[t++] = { i, 0 };
		while (t > 0) {
            user data = S[--t];
			for (int j = 1; j <= N; j++) {
				if (data.u == j) continue;
				if (U[j] < data.c + 1) continue;
				if (ARR[data.u][j] == 0) continue;
				U[j] = data.c + 1;
				S[t++] = { j, data.c + 1 };
			}
		}
		int rst = 0;
        for (int j = 1; j <= N; j++) rst += U[j];
        vec.push_back(pair<int, int>(rst, i));
	}
	sort(vec.begin(), vec.end());
	cout << vec[0].second << endl;
	return 0;
}
