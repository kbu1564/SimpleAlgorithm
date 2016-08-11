#include <iostream>
using namespace std;
int A[10],ai;
int main() {
  int n; cin >> n;
  for (int i = 0; n > 0; i++) {
    A[i] = n%10;
    n = n/10;
    ai++;
  }
  for (int i = 0; i < ai; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}

