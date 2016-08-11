#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main() {
  int n, m, X[51] = { 0, }, Y[51] = { 0, };
  char MAP[51][51] = { 0, };
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> MAP[i][j];
      if (MAP[i][j] != '.') {
        X[j]++;
        Y[i]++;
      }
    }
  }

  int cx = 0, cy = 0;
  for (int i = 0; i < n; i++) {
    if (Y[i] == 0) cy++;
  }
  for (int i = 0; i < m; i++) {
    if (X[i] == 0) cx++;
  }

  cout << max(cx, cy) << endl;
  return 0;
}

