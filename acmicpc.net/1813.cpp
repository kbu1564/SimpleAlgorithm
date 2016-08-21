#include <cstdio>
#include <iostream>
using namespace std;
int DP[100001];
int main() {
	int maxTrue = 0;
	int N; scanf("%d", &N);
	for (int i = 0; i < 100001; i++) DP[i] = -1;
	for (int i = 0; i < N; i++) {
		int ni; scanf("%d", &ni);
		if (DP[ni] < 0) DP[ni] = 0;
		DP[ni]++;
		maxTrue = max(maxTrue, ni);
	}
	
	int result = -1;
	for (int i = 0; i <= maxTrue; i++)
		if (DP[i] == i)
			result = max(result, DP[i]);

	cout << ((result < 0 && DP[0] <= 0)? 0: result) << endl;
	return 0;
}

