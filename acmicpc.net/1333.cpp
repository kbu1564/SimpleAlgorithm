#include <iostream>
using namespace std;

int MUSIC[1100000];
int main() {
	int N, L, D;
	cin >> N >> L >> D;

	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) MUSIC[idx++] = 1;
		// result ~ result + 5 까지 들을 수 있는 구간
		idx += 5;
	}

	int ring = 0;
	int result = 0;
	while (true) {
		//cout << ring << " : " << MUSIC[ring] << endl;
		// ring ~ ring + 1 까지 벨이 울림
		if (MUSIC[ring] == 0) {
			result = ring;
			break;
		}
		ring += D; // 이후 D초 뒤에 다시 울림
	}

	cout << result << endl;
	return 0;
}

