#include <cstdio>
#include <iostream>
using namespace std;

inline long long _min(long long a, long long b) { return a > b? b: a; }
inline long long _abs(long long x) { return x < 0? -x: x; }

long long IN[100001];
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &IN[i]);
	}

	// IN[0]을 기준으로 mid 간격의 거리만큼씩 전봇대를 위치한다는 가정
	// 간격을 binary_search
	long long result = 1e9 * 1e5;
	long long low = 0, hight = 1e9;
	while (low < hight) {
		long long totalMove = 0;
		long long mid = (low + hight) / 2;
		long long nextMovePoint = IN[0] + mid;
		for (int i = 1; i < N; i++) {
			totalMove += _abs(nextMovePoint - IN[i]);
			nextMovePoint += mid;
		}

		cout << nextMovePoint << " : " << (N-1) * mid << "(" << mid << ")" << endl;
		cout << "total move : " << totalMove << "(" << result << ")" << endl;
		cout << low << " ~ " << hight << endl << endl;
		// mid 이동으로 전봇대를 이동 가능할 경우
		// 0 번째 제외?!
		if (totalMove <= result) {
			hight = mid;
			result = _min(result, totalMove);
		} else {
			low = mid + 1;
		}
	}

	printf("%lld\n", result);
	return 0;
}
