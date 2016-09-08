#include <cstdio>
#include <iostream>
using namespace std;

template <typename T>
inline void _swap(T& a, T&b) { T t = a; a = b; b = t; }

template <typename T, const int MAXSIZE = 100001>
struct heap {
	int size;
	T ARR[MAXSIZE];

	bool empty() { return size <= 0; }
	T top() { return ARR[1]; }

	void push(T v) {
		ARR[++size] = v;
		for (int k = size; k > 1 && ARR[k] < ARR[k>>1]; k>>=1)
			_swap(ARR[k], ARR[k>>1]);
	}

	void pop() {
		ARR[1] = ARR[size--];

		int curr = 1;
		while (curr + curr + 1 <= size + 1) {
			if (ARR[curr+curr] < ARR[curr+curr+1]) {
				_swap(ARR[curr+curr], ARR[curr]);
				curr = curr + curr;
			} else if (ARR[curr+curr+1] < ARR[curr+curr]) {
				_swap(ARR[curr+curr+1], ARR[curr]);
				curr = curr + curr + 1;
			} else break;

			if (ARR[curr] < ARR[curr>>1])
				_swap(ARR[curr], ARR[curr>>1]);
		}
	}
};

struct node {
	int x, y, z;
};

node P[100001];
heap<node> Q;
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &P[i].x, &P[i].y, &P[i].z);
	}
	return 0;
}
