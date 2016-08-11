#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
int n,k,AC[51][51],NL[51],SCK[36][51],CN[37];
char NS[51][51];
int convNum(char c) { return c>='0'&&c<='9'? c-'0': c-'A'+10; }
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> NS[i];
    NL[i] = strlen(NS[i]);
    for (int j = NL[i]-1, l = 0; j >= 0; j--, l++) {
      int cvt = convNum(NS[i][j]);
      AC[i][l] = cvt;
      SCK[cvt][l]++;
    }
  }
  cin >> k;

  for (int i = 0; i < 36; i++) {
    printf("%02d\n", i);
    for (int l = 0; l < 51; l++) printf("%d ", SCK[i][l]*(35-i));
    printf("\n\n");
  }

  // find choice number
  for (int i = 0; i < k; i++) {
    int mn = 0;
    for (int l = 0; l < 36; l++) {
      for (int j = 0; j < 51; j++) {
        SCK[l][j]
      }
    }
  }
  return 0;
}

