#include <iostream>
using namespace std;
int main() {
	int C; cin >> C;
	for (int i = 0; i < C; i++) {
		double SCORE[1001] = { 0, };
		int N; cin >> N;

		double total = 0;
		for (int j = 0; j < N; j++) {
			cin >> SCORE[j];
			total += SCORE[j];
		}

		int goodCount = 0;
		double avg = total / (double)N;
		for (int j = 0; j < N; j++) {
			if (avg < SCORE[j]) goodCount++;
		}

		cout << fixed;
		cout.precision(3);
		cout << (goodCount / (double)N) * 100.0 << "%" << endl;
	}
	return 0;
}
