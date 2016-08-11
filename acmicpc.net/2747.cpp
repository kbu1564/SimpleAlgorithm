#include <iostream>
#include <stdio.h>
using namespace std;
int n, s1, s2 = 1, p = 1;
int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      p = s1 + s2;
      s1 = s2;
      s2 = p;
    }
    if (n == 0) cout << 0 << endl;
    else cout << p << endl;
    return 0;
}

