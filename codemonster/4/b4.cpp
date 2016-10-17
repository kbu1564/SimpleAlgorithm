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

const int MAX = 501;

int T, N;
double X[MAX];
double Y1[MAX], Y2[MAX];

double getDist(double x1, double y1, double x2, double y2) {
	double dx = abs(x1 - x2);
	double dy = abs(y1 - y2);
	return sqrt(dx * dx + dy * dy);
}

inline bool isLessEquals(double a, double b) {
	return a < b || abs(a-b) < 1e-8;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);

		for (int i = 0; i < MAX; i++) X[i] = Y1[i] = Y2[i] = 0.0;
		for (int i = 1; i <= N; i++) scanf("%lf %lf %lf", &X[i], &Y1[i], &Y2[i]);

		vector<double> lq, rq;

		// 시작점
		lq.push_back(Y1[1]); lq.push_back(Y2[1]);
		if (isLessEquals(Y1[1], Y1[2]) && isLessEquals(Y1[2], Y2[1])) lq.push_back(Y1[2]);
		if (isLessEquals(Y1[1], Y2[2]) && isLessEquals(Y2[2], Y2[1])) lq.push_back(Y2[2]);

		// 도착점
		rq.push_back(Y1[N]); rq.push_back(Y2[N]);
		if (isLessEquals(Y1[N], Y1[N-1]) && isLessEquals(Y1[N-1], Y2[N])) rq.push_back(Y1[N-1]);
		if (isLessEquals(Y1[N], Y2[N-1]) && isLessEquals(Y2[N-1], Y2[N])) rq.push_back(Y2[N-1]);

		double result = 2e11;

		// start point : left
		// end point   : right
		for (auto& end : rq) {
			double answer = 0.0;

			for (auto& start : lq) {
				double mody[MAX] = { 0, };

				// 후보군으로 선택
				mody[1] = start;
				mody[N] = end;

				// start -> end 최단 경로 = 두 지점을 고무줄로 연결한 경우 그 고무줄의 경로
				double nxt = X[N],  nyt = end;

				// 오차 수정
				bool update = true;
				while (update) {
					update = false;
					double cxs = X[1], cxt = X[N];
					double cys = start, cyt = end;

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
					// dx * y = dy * x + dx * b
					for (int i = 2; i <= N-1; i++) {
						// 기울기 재 계산
						double dx = cxt - cxs;
						double dy = cyt - cys;
						double a = dy / dx;
						double b = cys - a * cxs;

						double curry = a * X[i] + b;
						if (mody[i] > 0.0) curry = mody[i];
						if (Y1[i] > curry || Y2[i] < curry) {
							// 범위 벗어난 곳 발견

							// 오차 수정
							// curry 기준으로 Y1[i], Y2[i]의 편차 계산
							long long devy1 = floor(abs(curry - Y1[i]) * 10000);
							long long devy2 = floor(abs(curry - Y2[i]) * 10000);

							mody[i] = Y2[i];
							if (devy1 < devy2) mody[i] = Y1[i];

							update = true;
							// 변경된 값 적용
							cxs = X[i];
							cys = mody[i];
							if (nxt == 0.0 && nyt == 0.0) {
								nxt = X[i];
								nyt = mody[i];
							}
						}
					}
				}

				answer = 0.0;
				double sx = X[1], sy = mody[1];
				for (int i = 2; i <= N; i++) {
					if (mody[i] <= 0.0) continue;
					answer += getDist(sx, sy, X[i], mody[i]);
					sx = X[i];
					sy = mody[i];
				}
				if (result > answer) result = answer;
			}
		}
		printf("%.2lf\n", result);
	}
	return 0;
}

