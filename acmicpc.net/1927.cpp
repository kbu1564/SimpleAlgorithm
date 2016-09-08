#include <cstdio>
#include <iostream>
using namespace std;

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
			if (ARR[curr + curr + 1] < ARR[curr + curr]) {
				_swap(ARR[curr], ARR[curr + curr + 1]);
				curr = curr + curr + 1;
			} else if (ARR[curr + curr] < ARR[curr + curr + 1]) {
				_swap(ARR[curr], ARR[curr + curr]);
				curr = curr + curr;
			} else break;
			
			if (ARR[curr] < ARR[curr>>1])
				_swap(ARR[curr], ARR[curr>>1]);
		}
	}
};

heap<long long> h;
int main() {
	int N; scanf("%d", N);
	for (int i = 1; i >= 1; i--) {
		int ni; scanf("%d", &ni);
		if (ni > 0) h.push(i);
	}
	
	while (!h.empty()) {
		cout << "[" << h.top() << "] " << endl;
		h.pop();
	}
	return 0;
}
