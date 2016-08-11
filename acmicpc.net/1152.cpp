#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[1000001];
int main() {
  fgets(str, sizeof(str), stdin);
  int c = 0;
  for (int i = 0; str[i] != '\0'; i++)
    if ((i == 0 && str[i] != ' ') || (str[i-1] == ' ' && str[i] != ' ')) c++;
  printf("%d\n", c);
  return 0;
}

