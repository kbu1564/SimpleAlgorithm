#include <iostream>
#include <set>
using namespace std;

int DP[100001];
int main() {
	int N; cin >> N;

	for (int i = 0; i <= 1e5; i++) DP[i] = 1e9;

	//DP[0] = DP[1] = 1;
	// 기본값을 전부 1^2 을 기준으로 만들었을때로 초기화
	for (int i = 0; i * i <= 1e5; i++) DP[i*i] = 1;

	for (int i = 2; i <= N; i++)
		for (int j = 1; j * j <= 1e5; j++)
			if (j*j <= i)
				DP[i] = min(DP[i], DP[i-j*j] + 1);

	cout << DP[N] << endl;
	return 0;
}
