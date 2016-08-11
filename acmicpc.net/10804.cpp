#include <iostream>
using namespace std;
int A[20];
int main() {
  for (int i = 0; i < 20; i++) A[i] = i+1;
  for (int i = 0; i < 10; i++) {
    int s, e; cin >> s >> e;
    while (s < e) {
      int t = A[s-1];
      A[s-1] = A[e-1];
      A[e-1] = t;
      s++; e--;
    }
  }
  for (int i = 0; i < 20; i++)
    cout << A[i] << " ";
  cout << endl;

  return 0;
}

