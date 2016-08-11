#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
char n[10];
int main() {
  scanf("%s", n);
  int num = 0;
  int nl = strlen(n);
  for (int i = nl-1,j = 0; i >= 0; i--,j++) {
    int nx = n[i]-'0';
    if (n[i] >= 'A') {
      nx = 10 + (n[i] - 'A');
    }
    num += pow(16, j) * nx;
  }
  cout << num << endl;
  return 0;
}

