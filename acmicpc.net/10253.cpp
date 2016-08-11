#include <iostream>
using namespace std;

int T, a, b, i, j;

int gcd(int a, int b) {
  return b ? gcd(b, a%b): a;
}

int lcm(int a, int b) {
  return a * (b / gcd(a, b));
}

int main() {
  scanf("%d", &T);
  for (i = 0; i < T; i++) {
    j = 2;
    scanf("%d %d", &a, &b);
    while (a > 1) {
      for (;b > j * a; j++);
      int l = lcm(b, j);
      a = (l / b) * a - (l / j);
      b = l;
      int g = gcd(b, a);
      a /= g;
      b /= g;
    }
    printf("%d\n", b);
  }
  return 0;
}

