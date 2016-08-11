#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
int n,DP[101][2];
int main() {
  cin >> n;

  DP[0][0] = DP[0][1] = n;
  DP[1][0] = n-1;
  for (int i = 2; i < n; i++) {
    DP[i][0] = DP[i-2][0] * DP[i-1][1];
    DP[i][1] = DP[i-2][1] * DP[i-1][0];
  }

  cout << DP[n-1][0]+DP[n-1][1] << endl;
  return 0;
}
/*
1 - 2 - X

  - 3 - 2 - X

  - 4 - 3 - 2
      - 2 - X

  - 5 - 4 - 3
      - 3 - 2
      - 2 - X

