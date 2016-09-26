#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int t,n,S,a[1001],D[1001][1001];
int cards(int pj, int pn, int pS) {
  if (pS <= 0 || pj >= n) return 0;
  if (pn <= 0) return a[pj];
  if (D[pj][pn-1] == 0)
    D[pj][pn-1] = max(pS - cards(pj+1,pn,pS-a[pj]), pS - cards(pj,pn-1,pS-a[pn-1]));
  return D[pj][pn-1];
}

int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n), S = 0;
    memset(D, 0, sizeof(D));
    for (int j = 0; j < n; j++) scanf("%d", &a[j]), S += a[j];
    printf("%d\n", cards(0, n, S));
  }
  return 0;
}
