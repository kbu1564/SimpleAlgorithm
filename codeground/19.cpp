#include <cstdio>
#include <iostream>
using namespace std;

template <typename T>
inline void _swap(T& a, T& b) { T t = a; a = b; b = t; }

template <typename T, const int MAXSIZE = 100001>
struct heap {
	int size;
	T ARR[MAXSIZE];

	T top()      { return ARR[1]; }
	bool empty() { return size <= 0; }

	void push(T x) {
		ARR[++size] = x;
		
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
			
			if (ARR[curr] < ARR[curr/2])
				_swap(ARR[curr], ARR[curr/2]);
		}
	}
};

template <typename T>
void sort(T arr[], int s, int e) {
	heap<T> Q;
	for (int i = s; i < e; i++) Q.push(arr[i]);

	int idx = 0;
	while (!Q.empty()) {
		arr[idx++] = Q.top(); Q.pop();
	}
}

struct Interval {
	int s, e;
	bool operator<(const Interval& i) const {
		if (e == i.e) {
			return s < i.s;
		}
		return e > i.e;
	}
};

int binary_search(int ARR[], int s, int e, int v) {
	if (s == e) return s;

	int mid = (s + e)/2;
	if (ARR[mid] > v) return binary_search(ARR, s, mid, v);
	if (ARR[mid] <= v) return binary_search(ARR, mid+1, e, v);
	return mid;
}

int T, N;
Interval IN[100001];
int DP[100001];
int lis() {
	DP[0] = -1e9;
	int maxInterval = 0;
	for (int i = 0; i < N; i++) {
		int pos = binary_search(DP, 0, maxInterval + 1, IN[i].s);
		DP[pos] = IN[i].s;
		if (maxInterval < pos) maxInterval = pos;
	}
	return maxInterval;
}

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) DP[i] = 0;
		for (int j = 0; j < N; j++) scanf("%d %d", &IN[j].s, &IN[j].e);
		sort(IN, 0, N);
		
		printf("Case #%d\n", i);
		for (int j = 0; j < N; j++) printf("%d %d\n", IN[j].s, IN[j].e);
		printf("%d\n", lis());
	}
	return 0;
}

