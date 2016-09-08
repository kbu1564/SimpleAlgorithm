#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
inline T _abs(T a) { return a < 0? -a: a; }

template <typename T>
inline void _swap(T& a, T& b) { T t = move(a); a = move(b); b = move(t); }

template <typename T, const int MAXSIZE = 200001>
struct heap {
	int size;
	T ARR[MAXSIZE];
	
	bool empty() { return size <= 0; }
	T top() { return ARR[1]; }
	
	void push(T x) {
		ARR[++size] = x;
		
		for (int k = size; k > 1 && ARR[k] < ARR[k>>1]; k>>=1)
			_swap(ARR[k>>1], ARR[k]);
	}
	
	void pop() {
		ARR[1] = ARR[size--];
		
		int curr = 1;
		while (curr + curr + 1 <= size + 1) {
			if (ARR[curr + curr] < ARR[curr + curr + 1]) {
				_swap(ARR[curr], ARR[curr + curr]);
				curr = curr + curr;
			} else if (ARR[curr + curr + 1] < ARR[curr + curr]) {
				_swap(ARR[curr], ARR[curr + curr + 1]);
				curr = curr + curr + 1;
			} else break;
			
			if (ARR[curr] < ARR[curr>>1])
				_swap(ARR[curr], ARR[curr>>1]);
		}
	}
};

struct item {
	long long n;
	bool operator<(const item& i) const {
		if (_abs(n) == _abs(i.n)) {
			return n <= i.n;
		}
		return _abs(n) < _abs(i.n);
	}
};

heap<item> Q;
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		long long A; scanf("%lld", &A);
		if (A != 0)
			Q.push({ A });
		else {
			if (Q.empty()) {
				printf("0\n");
			} else {
				printf("%lld\n", Q.top().n);
				Q.pop();
			}
		}
	}
	return 0;
}
