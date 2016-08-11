#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
  return b? gcd(b, a%b): a;
}

int t,k,c;
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &k, &c);
    if (k == 1) {
      if (c == 2) printf("1\n");
      else if (c == 1) printf("2\n");
      else printf("IMPOSSIBLE\n");
      continue;
    } else if (c == 1) {
      printf("%d\n", k+1);
      continue;
    }
    if (k%c == 0) {
      printf("IMPOSSIBLE\n");
    } else {
      int g = gcd(k, c);
      // kx + 1 = cy;
      int q, r, s, t;
      int r1 = k, r2 = c;
      int s1 = 1, s2 = 0;
      int t1 = 0, t2 = 1;
      while (r2 > 0) {
        q = r1 / r2;

        r = r1 - r2 * q;
        r1 = r2;
        r2 = r;

        s = s1 - s2 * q;
        s1 = s2;
        s2 = s;

        t = t1 - t2 * q;
        t1 = t2;
        t2 = t;
      }

      while (t1 < 0) t1 += k;
      if (t1 > 1000000000) printf("IMPOSSIBLE\n");
      else printf("%d\n", t1);
    }
  }
  return 0;
}

