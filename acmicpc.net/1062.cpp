#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int N, K;
int KNOWN[256];
char STR[51][20];
int DP[2100000];
map<string, int> MM;

struct item {
	int know, i, k;
};

int main() {
	// anta ~ tica로 시작하고 끝나므로 무조건 아래 단어를 알아야 한다.
	KNOWN['a'] = KNOWN['n'] = KNOWN['t'] = KNOWN['i'] = KNOWN['c'] = 1;
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> STR[i];
	for (int i = 0; i < N; i++) {
		int C[256] = { 0, };
		for (int j = 0; STR[i][j]; j++)
			C[STR[i][j]]++;
		
		int cnt = 0;
		for (int j = 'a'; j <= 'z'; j++)
			if (C[j] > 0 && KNOWN[j] == 0)
				cnt++;
		
		if (cnt > K - 5) continue;
		
		int idx = 0;
		char KNOWNSTR[20] = { 0, };
		for (int j = 'a'; j <= 'z'; j++)
			if (C[j] > 0 && KNOWN[j] == 0)
				KNOWNSTR[idx++] = j;
		MM[KNOWNSTR]++;
	}
	
	int IDX[255] = { 0, };
	for (int w = 'a', i = 0; w <= 'z'; w++) {
		if (w != 'a' && w != 'n' && w != 't' && w != 'i' && w != 'c') {
			IDX[w] = i++;
		} else {
			IDX[w] = -1;
		}
	}
	
	int answer = 0;
	queue<item> Q;
	Q.push({ 0, 'b', K-5 });
	while (!Q.empty()) {
		item data = Q.front(); Q.pop();
		
		if (data.k < 0) continue;
		if (data.i - 1 > 'z') continue;
		if (IDX[data.i] == -1) {
			Q.push({ data.know, data.i + 1, data.k });
			continue;
		}
		if (DP[data.know] <= 0) {
			int result = 0;
			for (auto& e : MM) {
				result += e.second;
				for (int j = 0; e.first[j]; j++) {
					if ((data.know & (1 << IDX[e.first[j]])) == 0) {
						result -= e.second; break;
					}
				}
			}
			answer = max(answer, DP[data.know] = result);
		}
		
		Q.push({ data.know, data.i + 1, data.k });
		if ((data.know & (1 << IDX[data.i])) == 0) {
			Q.push({ data.know | (1 << IDX[data.i]), data.i + 1, data.k - 1 });
		}
	}
	
	cout << answer << endl;
	return 0;
}

