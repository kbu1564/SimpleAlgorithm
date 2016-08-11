#include <iostream>
#include <math.h>
using namespace std;
int main() {
  long long x; cin >> x;

  double n = sqrt(2*x);
  long long fc = n*(n-1)/2;
  while (fc*(fc-1)/2 > x) fc--;
  while (fc*(fc-1)/2 < x) fc++;

  long long nx = fc-1;
  long long ec = nx*(nx+1)/2-x;
  long long sx = nx%2? 1+ec: nx-ec;
  long long sy = nx%2? nx-ec: 1+ec;

  cout << sx << '/' << sy << endl;
  return 0;
}

