#include <iostream>
#include <string>
using namespace std;
int a[255];
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    char c = str.at(i);
    c = (c >= 'a' && c <= 'z')? 'A' + (c - 'a'): c;
    a[c]++;
  }
  char mc = 0;
  int mx = 0, sc = 0;
  for (int i = 0; i < 255; i++) {
    if (mx < a[i]) {
      mx = a[i];
      mc = i;
      sc = 0;
    } else if (mx == a[i]) {
      sc++;
    }
  }
  cout << (sc?'?':mc) << endl;
  return 0;
}

