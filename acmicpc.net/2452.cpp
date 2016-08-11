#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
//#define DEBUG
using namespace std;
typedef struct { int x, y; } _pos;
typedef struct { _pos p; vector<int> n; int i; } _posext;
int AX[4] = {0, 1, 0, -1}, AY[4] = {-1, 0, 1, 0};
int n,m,M[101][101],A[101][101],V[101][101],F,R;
_pos Q[50000];
vector<_posext> VAI;
int main() {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) scanf("%d", &M[i][j]);

  int result = 0;
  while (true) {
    VAI.clear();
#ifdef DEBUG
    cout << "#################### start debug message #####################" << endl;
    cout << "                     turn : " << result << endl;
    cout << endl;
    cout << "Original" << endl;
    for (int i = 0; i < m; i++) { for (int j = 0; j < n; j++) cout << M[i][j] << " "; cout << endl; }
    cout << endl;
#endif

    // A & AI setting
    memset(V, 0, sizeof(V));
    int an = 1, cc = 0;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
      if (V[i][j] == 1) continue;

      F = R = 0;
      cc = M[i][j];
      Q[F++] = (_pos){ j, i };
      VAI.push_back((_posext){ { j, i }, vector<int>(), an });
      while (R < F) {
        _pos p = Q[R++];
        if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) continue;
        if (V[p.y][p.x] == 1) continue;
        V[p.y][p.x] = 1;
        A[p.y][p.x] = an;
        for (int k = 0; k < 4; k++) {
          int nx = p.x + AX[k], ny = p.y + AY[k];
          if (V[ny][nx] == 0 && M[ny][nx] == cc) Q[F++] = (_pos){ nx, ny };
        }
      }
      an++;
    }
    if (VAI.size() == 1) break;

    // mxpos & AI.n setting
    memset(V, 0, sizeof(V));
    int AC = VAI.size();
    _posext mxpos = (_posext){ 0, };
    for (int i = 0; i < AC; i++) {
      int NA[10001] = {0, };

      F = R = 0;
      Q[F++] = VAI[i].p;
      cc = M[VAI[i].p.y][VAI[i].p.x];
      while (R < F) {
        _pos p = Q[R++];
        if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) continue;
        if (V[p.y][p.x] == 1) continue;
        V[p.y][p.x] = 1;
        for (int k = 0; k < 4; k++) {
          int nx = p.x + AX[k], ny = p.y + AY[k];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (A[ny][nx] != VAI[i].i) NA[A[ny][nx]]++;
          if (M[ny][nx] == cc && V[ny][nx] == 0) Q[F++] = (_pos){ nx, ny };
        }
      }
      for (int j = 1; j <= AC; j++) if (VAI[i].i != j && NA[j] > 0) VAI[i].n.push_back(j);
        if (mxpos.n.size() < VAI[i].n.size()) mxpos = VAI[i];
#ifdef DEBUG
        cout << VAI[i].i << " : (" << VAI[i].p.x << ", " << VAI[i].p.y << "), WITH : " << VAI[i].n.size() << endl;
#endif
      }

#ifdef DEBUG
      cout << endl;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cout << A[i][j] << " ";
        cout << endl;
      }
#endif

    // max merge !!
#ifdef DEBUG
    cout << endl;
#endif
    memset(V, 0, sizeof(V));
    int nc = mxpos.n.size();
    for (int i = 0; i < nc; i++) {
      int ni = mxpos.n[i];
#ifdef DEBUG
      cout << "MAX N : " << ni << "(" << VAI[ni-1].p.x << ", " << VAI[ni-1].p.y << ")" << endl;
#endif

      F = R = 0;
      Q[F++] = (_pos){ VAI[ni-1].p.x, VAI[ni-1].p.y };
      while (R < F) {
        _pos p = Q[R++];
        if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) continue;
        if (V[p.y][p.x] == 1) continue;
        V[p.y][p.x] = 1;
        A[p.y][p.x] = mxpos.i;
        for (int k = 0; k < 4; k++) {
          int nx = p.x + AX[k], ny = p.y + AY[k];
          if (V[ny][nx] == 0 && A[ny][nx] == ni) Q[F++] = (_pos){ nx, ny };
        }
      }
      // merge setting
      VAI[ni-1].i = mxpos.i;
      int ainl = VAI[ni-1].n.size();
      for (int j = 0; j < ainl; j++) {
        if (VAI[ni-1].n[j] == mxpos.i) {
          VAI[ni-1].n.erase(VAI[ni-1].n.begin() + j);
          break;
        }
      }
#ifdef DEBUG
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < n; k++) cout << A[j][k] << " ";
        cout << endl;
      }
      cout << endl;
#endif
    }

    memset(V, 0, sizeof(V));
    F = R = 0;
    Q[F++] = (_pos){ mxpos.p.x, mxpos.p.y };
    int rmap = 1 - M[mxpos.p.y][mxpos.p.x];
    while (R < F) {
      _pos p = Q[R++];
      if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) continue;
      if (V[p.y][p.x] == 1) continue;
      V[p.y][p.x] = 1;
      M[p.y][p.x] = rmap;
      for (int k = 0; k < 4; k++) {
        int nx = p.x + AX[k], ny = p.y + AY[k];
        if (V[ny][nx] == 0 && A[ny][nx] == mxpos.i) Q[F++] = (_pos){ nx, ny };
      }
    }
#ifdef DEBUG
    cout << endl;
    AC = VAI.size();
    for (int i = 0; i < AC; i++) {
      cout << VAI[i].i << " : (" << VAI[i].p.x << ", " << VAI[i].p.y << "), WITH : " << VAI[i].n.size() << endl;
    }
    cout << endl;
    cout << "#################### end debug message #####################" << endl;
    cout << endl;
#endif
    result++;
  }
  cout << result << endl;
  return 0;
}

