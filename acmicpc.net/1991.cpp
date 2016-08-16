#include <iostream>
using namespace std;
int N;
char A[256][3], v, l, r;
void od(char R, int T) {
  if (R < 'A' || R > 'Z') return;
  for (int i = 0; i < 3; i++) {
    if (i == T) cout << R;
    od(A[R][i], T);
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> v >> A[v][0] >> A[v][1];
  }
  od('A', 0); cout << endl;
  od('A', 1); cout << endl;
  od('A', 2);
  return 0;
}
