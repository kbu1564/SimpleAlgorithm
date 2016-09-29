#include <iostream>
using namespace std;

struct item {
	int r, g;
};

int N, L;
item D[1001];
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int d;
		cin >> d;
		cin >> D[d].r >> D[d].g;
	}

	int curr = 0;
	int result = 0;
	while (curr < L) {
		if (D[curr].r > 0 && D[curr].g > 0) {
			result
		}
		curr++;
		result++;
	}
	return 0;
}
