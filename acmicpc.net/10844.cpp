#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int n;
int DP[101][10],MOD = 1000000000;
int dp(int i, int j) {
  if (i == 0) return 0;
  if (i < 0 || j < 0 || j > 9) return 0;
  if (i == 1 && j == 0) return 0;
  if (i == 1 && j > 0)  return 1;
  if (DP[i][j] == 0) DP[i][j] = (dp(i-1, j-1) + dp(i-1, j+1))%MOD;
  return DP[i][j];
}
int main() {
  scanf("%d", &n);
  long long s = 0;
  for (int j = 0; j < 10; j++) s += dp(n, j);
  printf("%lld\n", s%MOD);
  return 0;
}

