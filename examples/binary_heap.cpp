#include <iostream>
using namespace std;

template <typename T>
inline void _swap(T& a, T& b) { T t = move(a); a = move(b); b = move(t); }

template <typename T, const int MAXSIZE = 200001>
struct heap {
	int size;
	T ARR[MAXSIZE];
	
	inline bool empty() { return size <= 0; }
	inline T top() { return ARR[1]; }
	
	inline void push(T x) {
		ARR[++size] = x;
		
		for (int k = size; k > 1 && ARR[k] < ARR[k>>1]; k>>=1)
			_swap(ARR[k>>1], ARR[k]);
	}
	
	inline void pop() {
		ARR[1] = ARR[size--];
		
		int curr = 1;
		while (curr + curr + 1 <= size) {
			if (ARR[curr + curr + 1] < ARR[curr + curr]) {
				_swap(ARR[curr], ARR[curr + curr + 1]);
				curr = curr + curr + 1;
			} else if (ARR[curr + curr] < ARR[curr + curr + 1]) {
				_swap(ARR[curr], ARR[curr + curr]);
				curr = curr + curr;
			} else break;
		}
	}
};

heap<int, 300001> h;
int main() {
	for (int i = 300000; i >= 1; i--) {
		h.push(i);
	}

	while (!h.empty()) {
		cout << "[" << h.top() << "] " << endl;
		h.pop();
	}
	return 0;
}
