#include <iostream>
using namespace std;
int A[301][301],n,m,k,sx,sy,ex,ey;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> A[i][j];
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> sx >> sy >> ex >> ey;
    int s = 0;
    for (int si = sy-1; si < ey; si++) for (int sj = sx-1; sj < ex; sj++) s += A[sj][si];
    cout << s << endl;
  }
  return 0;
}

