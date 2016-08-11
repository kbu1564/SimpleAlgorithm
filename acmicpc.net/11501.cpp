#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <map>
using namespace std;
int t,n,D[1000001];
typedef struct { int idx, value; } _n;
_n Ni[1000001];
int c(const void* v1, const void* v2) { return (*(_n*)v2).value-(*(_n*)v1).value; }
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      _n ni = (_n){ j, 0 };
      scanf("%d", &ni.value);
      D[j] = ni.value;
      Ni[j] = ni;
    }
    qsort(Ni, n, sizeof(_n), c);

    int sidx = 0;
    long long gsp = 0;
    for (int j = 0; j < n; j++) {
      if (Ni[j].idx < sidx) continue;

      long long sp = 0;
      for (int k = sidx; k < Ni[j].idx; k++) sp += Ni[j].value - D[k];
      gsp += sp;
      sidx = Ni[j].idx + 1;
      //printf("%d(%d) ", Ni[j].value, Ni[j].idx);
    }
    printf("%lld\n", gsp < 0? 0: gsp);
  }
  return 0;
}

