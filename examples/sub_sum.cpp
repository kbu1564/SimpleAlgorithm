#include <iostream>
using namespace std;
int main() {
	int SUM[10001] = { 0, };

	// 입력이 0 ~ 10000까지 순차적으로 주어졌다고 가정
	int INPUT[10001] = { 0, };
	for (int i = 0; i < 10001; i++) INPUT[i] = i;

	int total = 0;
	for (int i = 0; i < 10001; i++) SUM[i] = (total += INPUT[i]);

	int a = 5, b = 499; // 5 ~ 499 까지의 부분합 구하기 O(1)
	int ans = SUM[b] - SUM[a-1];

	cout << ans << endl;
	return 0;
}
