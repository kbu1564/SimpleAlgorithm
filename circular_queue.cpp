#include <iostream>
using namespace std;

int main() {
  const int SIZE = 10000;
  int Q[SIZE] = { 0, };
  int f = 0, r = 0;

  for (int i = 0; i < 10; i++) {
    Q[r++] = i;
    r %= SIZE;
  }

  while (f != r) {
    cout << Q[f++] << endl;
    f %= SIZE;
  }
  return 0;
}
