#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int t, a, b;
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &a, &b);
    a = a % 10;
    int j = 1;
    int r = a;
    for (; j * 2 < b; j*=2) r = (r * r)%10;
    for (; j < b; j++) r = (r * a) % 10;
    printf("%d\n", r? r: 10);
  }
  return 0;
}


