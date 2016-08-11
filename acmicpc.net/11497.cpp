#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
int t,n,L[10001],Li[10001];
int compare(const void* a1, const void* a2) { return *(int*)a1-*(int*)a2; }
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    for (int j = 0; j < n; j++) scanf("%d", &L[j]);
    qsort(L, n, sizeof(int), compare);
    int cnt = 0;
    int li = 0, ri = n-1;
    while (li <= ri) {
      Li[li++] = L[cnt++];
      if (li < ri) Li[ri--] = L[cnt++];
    }

    int mx = 0;
    for (int j = 1; j < n; j++) {
      if (mx < abs(Li[j]-Li[j-1])) mx = abs(Li[j]-Li[j-1]);
    }
    printf("%d\n", mx);
    //for (int j = 0; j < n; j++) printf("%d ", Li[j]);
    //printf("\n");
  }
  return 0;
}

