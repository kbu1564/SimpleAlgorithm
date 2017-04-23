#include <iostream>
using namespace std;

// 정렬을 위한 temp 변수의 공간 확보
const int BUF_SIZE = 100001;

template <typename T>
void merge(T* arr, T* buf, int s, int e, int(*comp)(T&, T&)) {
  if (e - s < 2) return;
  int m = (e + s) / 2;
  merge(buf, arr, s, m, comp);
  merge(buf, arr, m, e, comp);

  int s1 = s, s2 = m;
  for (int i = s; i < e; i++) {
    if (s1 < m && (s2 >= e || comp(buf[s1], buf[s2]) > 0)) {
      arr[i] = buf[s1++];
    } else {
      arr[i] = buf[s2++];
    }
  }
}

template <typename T>
void sort(T* arr, int n, int(*comp)(T&, T&)) {
  T buf[BUF_SIZE];
  for (int i = 0; i < n; i++) buf[i] = arr[i];
  merge(arr, buf, 0, n, comp);
}

inline int comp(int& a, int& b) {
  return a > b;
}

int main() {
  int arr[10] = { 10, 8, 6, 4, 2, 1, 3, 5, 7, 9 };
  sort(arr, 10, comp);

  for (int i = 0; i < 10; i++) cout << arr[i] << " ";
  cout << endl;
  return 0;
}
