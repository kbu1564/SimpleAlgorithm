#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int MAP[501][501];
int DP[501][501];
const int AY[4] = { 1, -1, 0, 0 }, AX[4] = { 0, 0, 1, -1 };
int solve(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N) return 0;
	if (DP[y][x] > -1) return DP[y][x];
	
	DP[y][x] = 1;
	for (int k = 0; k < 4; k++) {
		if (MAP[y][x] < MAP[y+AY[k]][x+AX[k]]) {
			DP[y][x] = max(DP[y][x], solve(x+AX[k], y+AY[k]) + 1);
		}
	}
	return DP[y][x];
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < 501; i++)
		for (int j = 0; j < 501; j++)
			DP[i][j] = -1;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &MAP[i][j]);
	
	int result = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			result = max(result, solve(j, i) + 1);
	
	cout << result << endl;
	return 0;
}
