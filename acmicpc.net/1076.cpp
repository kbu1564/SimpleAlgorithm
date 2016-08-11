#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

const char colors[][8] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
int getColor(char* col) {
  for (int i = 0; i < 10; i++) {
    if (strcmp(colors[i], col) == 0)
      return i;
  }
  return 0;
}
int main() {
  char col1[8],col2[8],col3[8];
  cin >> col1 >> col2 >> col3;
  long long rst = getColor(col1) * 10 + getColor(col2);
  rst = rst * pow(10, getColor(col3))
  cout << rst << endl;
  return 0;
}

