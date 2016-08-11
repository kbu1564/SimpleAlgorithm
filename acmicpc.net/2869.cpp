#include <stdio.h>
#include <math.h>
long long a, b, v;
int main() {
  scanf("%lld %lld %lld", &a, &b, &v);
  long long r = (v-b)/(a-b);
  r = (v-b)%(a-b)? r+1: r;
  printf("%lld\n", r);
  return 0;
}
