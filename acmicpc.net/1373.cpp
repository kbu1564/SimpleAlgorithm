#include <stdio.h>
#include <string.h>
char bin[1000001],rtn[400000];
int main() {
  scanf("%1000000s", bin);
  int num8 = 0;
  int binl = strlen(bin);
  int bt8l = binl/3+(binl%3? 1: 0) - 1;
  for (int i = binl-1, j = 0; i >= 0; i--, j++) {
    num8 += (bin[i]=='1'? 1: 0) << (j%3);
    if (i == 0 || j%3 == 2) {
      rtn[bt8l-j/3] = num8+'0';
      num8 = 0;
    }
  }
  printf("%s\n", rtn);
  return 0;
}

