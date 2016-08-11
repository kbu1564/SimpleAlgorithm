#include <iostream>
#include <math.h>
using namespace std;
int x,y,w,h;
int main() {
  cin >> x >> y >> w >> h;
  int dl[4] = { x, y, w-x, h-y };
  int rst = 987654321;
  for (int i = 0; i < 4; i++) rst = min(rst, dl[i]);
  cout << rst << endl;
  return 0;
}

