#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

vector<char*> strs;
bool comp(const char *s1, const char *s2) {
  int l1 = strlen(s1), l2 = strlen(s2);
  return l1 < l2 || (l1 == l2 && strcmp(s1, s2) < 0);
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    char *str = new char[51];
    cin >> str;
    strs.push_back(str);
  }
  sort(strs.begin(), strs.end(), comp);
  for (int i = 0; i < t; i++) {
    if (i > 0) {
      if (strcmp(strs.at(i), strs.at(i-1)) == 0) continue;
    }
    cout << strs[i] << endl;
  }
  return 0;
}

