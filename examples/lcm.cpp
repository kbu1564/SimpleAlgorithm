#include <iostream>
using namespace std;
int gcd(int a, int b) { return !a ? b: gcd(b%a, a); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main() {
  // n, m의 최소 공배수 = (n * m) / (n과 m의 공약수중 최대 수)
  int n, m;
  cin >> n >> m;
  cout << lcm(n, m) << endl;
  return 0;
}
