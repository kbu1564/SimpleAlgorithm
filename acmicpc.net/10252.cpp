#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int t,m,n;
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &m, &n);

    printf("%d\n", 1);
    printf("(%d,%d)\n", 0, 0);
    for (int j = 0; j < m; j++) for (int k = 1; k < n; k++) printf("(%d,%d)\n", j, (j%2==0)? k: m-k+1);
    for (int j = m-1; j > 0; j--) printf("(%d,%d)\n", j, 0);
  }
  return 0;
}

