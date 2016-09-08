#include <cstdio>
#include <algorithm>

int main() {
	int result = 0, x, y;
	std::pair<int, int> ARR[101];
	int DP[101] = { 0, };
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &x, &y);
		ARR[i].first = x < y? x: y;
		ARR[i].second = x > y? x: y;
	}
	std::sort(ARR+1, ARR+N+1);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++)
			if (ARR[i].second >= ARR[j].second && DP[i] < DP[j] + 1)
				DP[i] = DP[j] + 1;
		result = result < DP[i]? DP[i]: result;
	}
	printf("%d\n", result);
	return 0;
}
