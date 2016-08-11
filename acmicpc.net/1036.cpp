#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
int n,k,mi;
int AC[36],IAC[51][36];
char num[51][51],str[51];
int c(const void* v1, const void* v2) {
  char* s1 = (char*)v1;
  char* s2 = (char*)v2;
  int s1l = strlen(s1);
  int s2l = strlen(s2);
  int s1ll = s1l > mi? s1l - mi: 0;
  int s2ll = s2l > mi? s2l - mi: 0;
  return strcmp(s1+s1ll, s2+s2ll);
//  return s2l-s1l == 0? strcmp(s1+s1ll, s2+s2ll): s2l-s1l;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%50s", num[i]);
    mi = max(mi, (int)strlen(num[i]));
  }
  scanf("%d", &k);

  int h = 0;
  int cidx = 0;
  while (true) {
    bool end = true;
    qsort(num, n, 51, c);

    for (int i = 0; i < n; i++) {
      int tcidx = cidx;
      int nl = strlen(num[i]);
      if (nl < mi || cidx >= nl) continue;
      if (nl >= mi) tcidx = nl-mi;
      end = false;

      int nm = 0;
      if (num[i][tcidx] >= '0' && num[i][tcidx] <= '9')
        nm = num[i][tcidx]-'0';
      else nm = num[i][tcidx]-'A'+10;

      if (nm != 35) {
        if (h <= k && AC[nm] == 0) h++;
        if (h <= k) {
          IAC[tcidx][nm]++;
          AC[nm]++;
        }
      }
    }

    if (end == true || h == k) break;
    cidx++;
    mi--;
  }

  for (int i = 0; i < n; i++) {
    int ck = 0;
    for (int j = 0; j < 36; j++) {
      ck = max(ck, IAC[i][j]*j);
    }
  }

  long long trtn = 0;
  for (int i = 0; i < n; i++) {
    long long rtn = 0;
    int nl = strlen(num[i]);
    for (int j = 0; j < nl; j++) {
      int nm = 0;
      if (num[i][j] >= '0' && num[i][j] <= '9') {
        nm = num[i][j]-'0';
      } else {
        nm = num[i][j]-'A'+10;
      }

      printf("%c", AC[nm]>0? 'Z': num[i][j]);
      if (AC[nm] > 0) nm = 35;

      rtn = rtn + nm * pow(36, nl-1-j);
    }
    printf("\n");
    trtn += rtn;
  }

  int sidx = 0;
  long long tmp = trtn;
  while (tmp > 0) {
    str[sidx++] = tmp%36>9? 'A'+(tmp%36-10): '0'+tmp%36;
    tmp /= 36;
  }

  int sl = strlen(str);
  for (int i = 0; i < sl; i++) printf("%c", str[sl-1-i]);
  printf("\n");
  return 0;
}

