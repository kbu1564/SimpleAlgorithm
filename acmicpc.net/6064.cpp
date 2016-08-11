#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
int tmp,t,n,m,x,y;
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d %d %d", &n, &m, &x, &y);
    if (n > m) {
      tmp = n; n = m; m = tmp;
      tmp = x; x = y; y = tmp;
    }
    
    int cnt = 0;
    int ty = x;
    while (ty != y) {
      if (cnt >= m) break;
      cnt++;
      ty -= m-n;
      if (ty <= 0) ty += m;
    }

    if (ty != y) printf("-1\n");
    else printf("%d\n", x+cnt*n);
  }
  return 0;
}
/*
11 13 6 5
1  1
2  2
3  3
4  4
5  5
6  6
7  7
8  8
9  9
10 10
11 11
1  12
2  13
3  1
4  2
5  3
6  4
7  5
8  6
9  7
10 8
11 9
1  10
2  11
3  12
4  13
5  1
6  2
 
10 12 3 9
1  1 <=
2  2
3  3
4  4
5  5
6  6
7  7
8  8
9  9
10 10
1  11
2  12
3  1  <=
4  2
5  3
6  4
7  5
8  6
9  7
10 8
1  9
2  10
3  11
4  12
5  1  <=
6  2
7  3
8  4
9  5
10 6
1  7
2  8
3  9  <= find!!
4  10
5  11
6  12
7  1  <=
8  2
9  3
10 4
1  5
2  6
3  7
4  8
5  9
6  10
7  11
8  12
9  1  <=
10 2
1  3
2  4
3  5
4  6
5  7
6  8
7  9
8  10
9  11
10 12 <= end!!
*/

