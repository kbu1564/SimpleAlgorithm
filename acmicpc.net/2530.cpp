#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
int TIME = 24 * 3600;
int a, b, c, d;
int main() {
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int t = (a * 3600 + b * 60 + c + d) % TIME;
  printf("%d %d %d\n", t/3600, t%3600/60, t%3600%60);
  return 0;
}

