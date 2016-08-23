#include <iostream>
using namespace std;

inline void swap(int& a, int& b) { int t = a; a = b; b = t; }

int ARR[10001];
int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> ARR[i];

	int heap[10001] = { 0, };
	int idx = 1;
	for (int i = 1; i <= N; i++) {
		// heap 추가 연산
		heap[idx++] = ARR[i];
		int curr = idx - 1;
		while (curr > 1) {
			if (heap[curr] < heap[curr/2])
				swap(heap[curr], heap[curr/2]);
			curr = curr / 2;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << heap[1] << " ";
		// heap 제거 연산
		swap(heap[1], heap[--idx]);

		int curr = 1;
		while (curr * 2 < idx - 1) {
			int child = curr * 2 + 1;
			if (curr * 2 + 1 > idx) child = curr * 2;
			if (heap[curr*2] < heap[curr*2+1]) child = curr * 2;

			if (heap[curr] > heap[child])
				swap(heap[curr], heap[child]);
			curr = child;
		}
	}
	cout << endl;
	return 0;
}
