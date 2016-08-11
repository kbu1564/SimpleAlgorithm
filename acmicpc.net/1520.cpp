#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int ax[4]={0,1,0,-1},ay[4]={-1,0,1,0};
int m,n,M[501][501],DP[501][501];
int dp(int i, int j) {
  if (i == 0 && j == 0) return DP[i][j] = 1;
  if (DP[i][j] == 0)
    for (int k = 0; k < 4; k++) if (M[i+ay[k]][j+ax[k]] > M[i][j]) DP[i][j] += dp(i+ay[k],j+ax[k]);
  return DP[i][j];
}
int main() {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) scanf("%d", &M[i][j]);
  printf("%d\n", dp(m-1, n-1));
  return 0;
}

