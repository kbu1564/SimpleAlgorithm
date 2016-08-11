#include <iostream>
#include <stdio.h>
using namespace std;
int t, n, s1, s2 = 1, p = 1;
int main() {
  cin >> t;
  for (int j = 0; j < t; j++) {
    s1 = 0, s2 = 1;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      p = s1 + s2;
      s1 = s2;
      s2 = p;
    }
    if (n == 0) cout << 1 << " " << 0 << endl;
    else cout << s1 << " " << p << endl;
  }
  return 0;
}

