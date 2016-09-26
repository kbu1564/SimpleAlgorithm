#include <iostream>
using namespace std;
int main() {
	int time = 0;
	int K; cin >> K; K--;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int T;
		char Z;
		cin >> T >> Z;
		time += T;
		if (time > 210) break;
		if (Z == 'T' || Z == 'P') {
			K = (K + 1) % 8;
		}
	}
	cout << K + 1 << endl;
	return 0;
}
