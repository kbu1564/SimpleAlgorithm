#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int N, M;
int DP[1001][1001]; // DP[i][j] = i*j 까지의 최대 사각형 넓이
int MAP[1001][1001];
int main() {
	int result = 0;
	
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char til; scanf(" %c", &til);
			DP[i][j] = MAP[i][j] = til - '0';
			result = max(result, DP[i][j]);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] + MAP[i-1][j] + MAP[i][j-1] + MAP[i-1][j-1] >= 4) {
				DP[i][j] = min(min(DP[i][j-1], DP[i-1][j]), DP[i-1][j-1]) + 1;
				result = max(result, DP[i][j]);
			}
		}
	}
	cout << result * result << endl;
	return 0;
}
