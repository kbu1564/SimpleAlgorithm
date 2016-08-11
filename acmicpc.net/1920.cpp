#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
int n,m;
map<int, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int v; scanf("%d", &v);
    mp.insert(pair<int, int>(v,1));
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int v; scanf("%d", &v);
    if (mp.find(v) == mp.end()) cout << 0 << endl;
    else cout << 1 << endl;
  }
  return 0;
}

