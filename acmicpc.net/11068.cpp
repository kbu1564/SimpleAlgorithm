#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int t,n,ix;
char buff[1000];
char* base(int n, int j) {
  ix = 0;
  while (n > 0) {
    buff[ix++] = n%j+'0';
    n = n/j;
  }
  buff[ix] = 0;
  return buff;
}
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    char* nn;
    bool is = true;
    for (int j = 2; j < 65; j++) {
      nn = base(n,j);
      is = true;
      for (int k = 0; k < ix; k++) {
        if (ix/2 <= k) break;
        if (nn[k] != nn[(ix-1)-k]) is = false;
      }
      if (is == true) break;
    }
    printf("%d\n", (is == true? 1: 0));
  }
  return 0;
}
