#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int n;
int main() {
  cin >> n;
  int ci = 0;
  int cn = n;
  while (true) {
    int n1 = cn/10, n2 = cn%10;
    int nr = n1 + n2;
    cn = n2*10 + nr%10;
    ci++;
    if (cn == n) break;
  }
  cout << ci << endl;
  return 0;
}

