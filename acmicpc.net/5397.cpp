#include <cstdio>
#include <iostream>
using namespace std;

template <typename T>
struct node {
	T val;
	int left, right;
	node() {}
	node(T v) {
		val = v;
		left = right = 0;
	}
};

template <typename T, const int MAXSIZE = 1000005>
struct list {
	int idx;
	node<T> root[MAXSIZE];

	list() : idx(1) {}
	
	int insert(int curr, T val) {
		int left = curr;
		int right = root[curr].right;

		root[idx] = node<T>(val);
		root[idx].left = left;
		root[idx].right = right;
		
		root[right].left = idx;
		root[left].right = idx;

		return idx++;
	}
	
	int remove(int curr) {
		int left = root[curr].left;
		int right = root[curr].right;
		
		root[left].right = right;
		root[right].left = left;
		
		return left;
	}
};

int idx;
char S[1000001];
list<char> LIST;

int main() {
	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> S;
		
		idx = 0;
		LIST.idx = 1;
		for (int i = 0; i < 1000005; i++) LIST.root[i] = { 0, };
		for (int i = 0; S[i]; i++) {
			if (S[i] == '<') {
				if (idx == 0) continue;
				idx = LIST.root[idx].left;
			} else if (S[i] == '>') {
				if (idx == LIST.root[0].left) continue;
				idx = LIST.root[idx].right;
			} else if (S[i] == '-') {
				if (idx == 0) continue;
				idx = LIST.remove(idx);
			} else {
				idx = LIST.insert(idx, S[i]);
			}
		}

		int curr = LIST.root[0].right;
		do {
			cout << LIST.root[curr].val;
			curr = LIST.root[curr].right;
		} while (LIST.root[curr].right != LIST.root[0].right);
		cout << endl;
	}
	return 0;
}
