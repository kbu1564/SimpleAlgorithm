#include <iostream>
#include <algorithm>
using namespace std;
int c,r,k,x = 1,y = 1;
int main() {
  cin >> c >> r >> k;
  if (c*r < k) {
    cout << 0 << endl;
    return 0;
  }
  int cnt = 1;
  while (c > 0) {
    cnt += c*2+r*2-4;
    c -= 2; r -= 2;
    x += 1; y += 1;
    if (cnt >= k) {
      c += 2; r += 2;
      x -= 1; y -= 1;
      cnt -= c*2+r*2-4;
      break;
    }
  }
  while (cnt < k) {
    for (int i = 1; i < r; i++) {
      if (cnt == k) break;
      y++; cnt++;
    }
    if (cnt == k) break;

    for (int i = 1; i < c; i++) {
      if (cnt == k) break;
      x++; cnt++;
    }
    if (cnt == k) break;

    for (int i = 1; i < r; i++) {
      if (cnt == k) break;
      y--; cnt++;
    }
    if (cnt == k) break;

    for (int i = 1; i < c-1; i++) {
      if (cnt == k) break;
      x--; cnt++;
    }
    if (cnt == k) break;
  }
  cout << x << " " << y << endl;
  return 0;
}

