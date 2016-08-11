#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int t,n,m,A[1000001];
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) scanf("%d", &A[j]);
    sort(A, A+n);

    cin >> m;
    for (int j = 0; j < m; j++) {
      int mm; scanf("%d", &mm);
      printf("%d\n", binary_search(A, A+n, mm)? 1: 0);
    }
  }
  return 0;
}

