#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int t,n,m,a,b,p,q;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    int S[1001]={0,}, A[1001]={0,};
    cin >> n >> m;
    for (int j = 0; j < m; j++) {
      cin >> a >> b >> p >> q;
      S[a] += p; A[a] += q;
      S[b] += q; A[b] += p;
    }

    float mx = 0.0f, mi = 987654321.0f; 
    for (int j = 1; j <= n; j++) {
      int s = S[j], a = A[j];
      float w = (s*s)/(float)(s*s+a*a);
      if (s == 0 && a == 0) w = 0.0f;
      mx = max(mx, w);
      mi = min(mi, w);
    }
    cout << floor(mx*1000) << endl;
    cout << floor(mi*1000) << endl;
  }
  return 0;
}
