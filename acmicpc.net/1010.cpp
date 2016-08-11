#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int t,n,m;
long long DP[30][30];
long long combi(int n, int r) {
  if (r < 0) return 0;
  if (n == r) return 1;
  if (DP[n][r] > 0) return DP[n][r];
  DP[n][r] = combi(n-1, r-1) + combi(n-1, r);
  return DP[n][r];
}
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> m;
    cout << combi(m, n) << endl;
  }
  return 0;
}
