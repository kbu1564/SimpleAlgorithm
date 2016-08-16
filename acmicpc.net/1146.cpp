#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int N, DP[101][101];
int main() {
  cin >> N;

	int result = 0;
	for (int i = 1; i <= N; i++) result = (result + DP[N][i]) % 1000000;
	cout << result << endl;
  return 0;
}
DP[1][1] = 1

DP[2][1] = 1
DP[2][2] = 1

DP[3][1] = 1
DP[3][2] = 2
DP[3][3] = 1

DP[4][1] = 2
DP[4][2] = 3
DP[4][3] = 3
DP[4][4] = 2

1 2
2 1


1 3 2
3 1 2

2 1 3
2 3 1


1 4 2 3
4 1 3 2  1 3 2 4

2 1 4 3  2 4 1 3
2 3 1 4  4 2 3 1

3 1 4 2  3 4 1 2
3 2 4 1


3 1 5 2 4  4 2 5 1 3
4 3 5 1 2  3 2 5 1 4

1 3 2 5 4  5 1 3 2 4
4 1 3 2 5  4 5 1 3 2

2 1 4 3 5  2 5 1 4 3
2 4 1 5 3  5 2 4 1 3

5 2 3 1 4  2 3 1 5 4
4 5 2 3 1  4 2 3 1 5

3 5 1 4 2  3 1 4 2 5
5 3 4 1 2  3 4 1 5 2

2 1 5 3 4  5 1 4 2 3
3 2 5 1 4  4 1 5 2 3

2 5 3 1 4

