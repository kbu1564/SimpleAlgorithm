#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int rvs(int n) {
  char s[5] = {0, };
  for (int i = 0; i < 5; i++) {
    if (n <= 0) break;
    s[i] = (n%10)+'0';
    n = n/10;
  }
  int sl = strlen(s);
  int rtn = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    rtn += (s[i]-'0')*pow(10,sl-1-i);
  }
  return rtn;
}
int main() {
  int n1, n2;
  cin >> n1 >> n2;
  cout << rvs(rvs(n1) + rvs(n2)) << endl;
  return 0;
}

