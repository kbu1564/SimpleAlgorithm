#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
int t,n;
long long int A[101] = { 1, 1, 1, 0 };
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    for (int j = 3; j < n; j++) {
      A[j] = A[j-3] + A[j-2];
    }
    printf("%lld\n", A[n-1]);
  }
  return 0;
}

