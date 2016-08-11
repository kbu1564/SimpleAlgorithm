#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
char s[20];
int n[10] = {6,2,5,5,4,5,6,3,7,5};
int main() {
  scanf("%s", s);
  int cn = 0, cc = 0;
  int sl = strlen(s);
  for (int i = 0; i < sl; i++) cc += n[s[i]-'0'], cn = cn * 10 + (s[i] - '0');

  int tcc = 0;
  int tdp = 1;
  int tnx = s[sl-tdp]-'0';
  tcc = cc + (n[tnx+1] - n[tnx])*(int)pow(10,tdp-1);
  return 0;
}

