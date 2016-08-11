#include <iostream>
#include <stdio.h>
using namespace std;
int n,r,g,b,DP[1001][3];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &r, &g, &b);
    if (i > 0) {
      DP[i][0] = min(DP[i-1][1] + r, DP[i-1][2] + r);
      DP[i][1] = min(DP[i-1][0] + g, DP[i-1][2] + g);
      DP[i][2] = min(DP[i-1][0] + b, DP[i-1][1] + b);
    } else {
      DP[i][0] = r, DP[i][1] = g, DP[i][2] = b;
    }
  }
  printf("%d\n", min(DP[n-1][0], min(DP[n-1][1], DP[n-1][2])));
  return 0;
}

