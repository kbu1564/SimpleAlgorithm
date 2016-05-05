#include <iostream>
using namespace std;

int main() {
  const int SIZE = 10000;
  int S[SIZE] = { 0, };
  int t = 0;

  for (int i = 0; i < 10; i++) {
    S[t++] = i;
  }

  while (t > 0) {
    cout << S[--t] << endl;
  }
  return 0;
}
