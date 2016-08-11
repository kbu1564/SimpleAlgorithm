#include <iostream>
using namespace std;

int N,X,C,arr[10001],ans[10001];
int main()
{
  scanf("%d %d", &N, &X);
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] < X) ans[C++] = arr[i];
  }
  for (int i = 0; i < C; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}

