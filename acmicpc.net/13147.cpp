#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int isPossible = 1;
map<string, int> S;
vector< vector<int> > MAP;
int P[10001], F[10001];
int maxSize;
void fi(int x) {
	P[x] = maxSize++;
	for (int i = 0; i < MAP[x].size(); i++) {
		int th = MAP[x][i];
		if (P[th] == -1) fi(th);
		else if (P[x] < P[th]) isPossible = 0;
	}
	F[x] = 1;
}

int main() {
	for (int i = 0; i < 10001; i++) P[i] = -1;

	int N; scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		char s1[21], s2[21];
		char dist;
		scanf("%s %c %s", &s1, &dist, &s2);

		string va = s1;
		string vb = s2;
		if (dist == '<') swap(va, vb);
		
		if (S.find(va) == S.end()) S.insert(map<string, int>::value_type(va, S.size()));
		if (S.find(vb) == S.end()) S.insert(map<string, int>::value_type(vb, S.size()));
		int ia = S[va], ib = S[vb];
		MAP[ia].push_back(ib);
	}
	int maxSize = S.size();
	for (int i = 0; i < maxSize; i++) {
		fi(i);
		if (isPossible == 0) break;
	}

	cout << (isPossible == 0? "impossible": "possible") << endl;
	return 0;
}

