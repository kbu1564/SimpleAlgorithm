#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

const int MAX = 100001;

int T, N;
long long X[MAX];
long long Y1[MAX], Y2[MAX];
long long mody[MAX];

long long getDist(long long x1, long long y1, long long x2, long long y2) {
	double dx = abs(x1 - x2);
	double dy = abs(y1 - y2);
	return sqrt(dx * dx + dy * dy);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);

		for (int i = 0; i < MAX; i++) X[i] = Y1[i] = Y2[i] = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%lld %lld %lld", &X[i], &Y1[i], &Y2[i]);
			X[i] *= 1000;
			Y1[i] *= 1000;
			Y2[i] *= 1000;
		}

		vector<long long> lq, rq;

		// 시작점
		lq.push_back(Y1[1]); lq.push_back(Y2[1]);
		if (Y1[1] <= Y1[2] && Y1[2] <= Y2[1]) lq.push_back(Y1[2]);
		if (Y1[1] <= Y2[2] && Y2[2] <= Y2[1]) lq.push_back(Y2[2]);

		// 도착점
		rq.push_back(Y1[N]); rq.push_back(Y2[N]);
		if (Y1[N] <= Y1[N-1] && Y1[N-1] <= Y2[N]) rq.push_back(Y1[N-1]);
		if (Y1[N] <= Y2[N-1] && Y2[N-1] <= Y2[N]) rq.push_back(Y2[N-1]);

		long long result = 2e14;

		// start point : left
		// end point   : right
		for (auto& end : rq) {
			long long answer = 0;

			for (auto& start : lq) {
				for (int i = 0; i < MAX; i++) mody[i] = 0;

				// 후보군으로 선택
				mody[1] = start;
				mody[N] = end;

				// start -> end 최단 경로 = 두 지점을 고무줄로 연결한 경우 그 고무줄의 경로
				long long nxt = X[N],  nyt = end;

				// 오차 수정
				bool update = true;
				while (update) {
					update = false;
					long long cxs = X[1], cxt = X[N];
					long long cys = start, cyt = end;

					// 기울기 = dy / dx
					// y = ax + b
					// a = dy / dx
					// b = start - a * X[1]
					if (nxt > 0.0 && nyt > 0.0) {
						cxt = nxt;
						cyt = nyt;
						nxt = nyt = 0.0;
					}

					// y = a * x + b
					for (int i = 2; i <= N-1; i++) {
						// 기울기 재 계산
						long long dx = cxt - cxs;
						long long dy = cyt - cys;
						long long a = dy / dx;
						long long b = cys - a * cxs;

						long long curry = a * X[i] + b;
						if (mody[i] > 0.0) curry = mody[i];
						if (Y1[i] <= curry && curry <= Y2[i]) continue;
						// 범위 벗어난 곳 발견

						// 오차 수정
						// curry 기준으로 Y1[i], Y2[i]의 편차 계산
						long long devy1 = abs(curry - Y1[i]);
						long long devy2 = abs(curry - Y2[i]);

						if (devy1 < devy2) {
							// Y1[i] 가 더 가까움
							mody[i] = Y1[i];
						} else {
							mody[i] = Y2[i];
						}

						update = true;
						// 변경된 값 적용
						cxs = X[i];
						cys = mody[i];
						if (nxt == 0 && nyt == 0) {
							nxt = X[i];
							nyt = mody[i];
						}
					}
				}

				answer = 0;
				long long sx = X[1], sy = mody[1];
				for (int i = 1; i <= N; i++) {
					//printf("%.2lf ", mody[i]/1000);
					if (mody[i] == 0) continue;
					if (i > 1) {
						answer += getDist(sx, sy, X[i], mody[i]);
						sx = X[i];
						sy = mody[i];
					}
				}
				result = min(result, answer);
				//printf(" = %.2lf\n", answer/1000);
			}
		}

		long long irst = floor(result);
		printf("%lld.%02lld\n", irst/1000, irst%1000/10 + (irst%1000%10 > 4? 1: 0));
	}
	return 0;
}

