#include <stdio.h>
#include <math.h>
int a[1001];
int main (void)
{
  int T, N, i;
  long long s, c, z;
  scanf ("%d", &T);
  while (T--)
  {
    scanf ("%d", &N);
    s = c = z = 0;
    for (i = 0; i < N; i++) { scanf ("%d", &a[i]); s += a[i]; if (a[i] == 0) z++; }
    for (i = 0; i < N; i++) if (a[i]*(N-z) > s) c++;
    printf("%.3f %.3f%%\n", s/(float)(N-z), c/(float)(N-z)*100.0f);
  }
}
