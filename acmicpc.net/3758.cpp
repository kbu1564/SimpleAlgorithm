#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct scoreboard {
	int uid;
	int total;
	int submission;
	int lastTime;
	int prob[101];
	bool operator<(const scoreboard& u) const {
		if (total == u.total) {
			if (submission == u.submission) {
				return lastTime < u.lastTime;
			}
			return submission < u.submission;
		}
		return total > u.total;
	}
};

int TC;
int N, K, T, M;
int main() {
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		scoreboard user[101] = { 0, };

		scanf("%d %d %d %d", &N, &K, &T, &M);
		for (int j = 0; j < M; j++) {
			int uid, pid, sco;
			scanf("%d %d %d", &uid, &pid, &sco);

			scoreboard& u = user[uid];

			u.uid = uid;
			u.lastTime = j;
			u.submission++;

			if (u.prob[pid] < sco) {
				// score 갱신
				u.total = u.total - u.prob[pid] + sco;
				u.prob[pid] = sco;
			}
		}

		sort(user+1, user+N+1);

		int result = 1;
		for (int j = 1; user[j].uid != T && j <= N; j++) result++;

		for (int j = 1; j <= N; j++) {
			printf("%d : %d - %d 제출, %dsec\n", user[j].uid, user[j].total, user[j].submission, user[j].lastTime);
		}

		printf("%d\n", result);
	}
	return 0;
}
