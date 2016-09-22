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

list<int> LIST;
int main() {
	int idx = 0;
	// begin <-> end 서로 연결되어 있다
	// LIST.root[0].right : 무조건 rootNode
	// LIST.root[0].left  : 무조건 마지막 Node

	// <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <->
	int idx00 = 0; // rootNode
	int idx10 = LIST.insert(idx00, 10);
	int idx20 = LIST.insert(idx10, 20);
	int idx30 = LIST.insert(idx20, 30);
	int idx40 = LIST.insert(idx30, 40);
	int idx50 = LIST.insert(idx40, 50);

	// 30 노드 뒤에 삽입
	// <-> 10 <-> 20 <-> 30 <-> 35 <-> 40 <-> 50 <->
	int idx35 = LIST.insert(idx30, 35);

	// print
	int curr = LIST.root[0].right;
	do {
		cout << LIST.root[curr].val << " ";
		curr = LIST.root[curr].right;
	} while (LIST.root[curr].right != LIST.root[0].right);
	cout << endl;

	// 35 노드 제거
	// <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <->
	idx30 = LIST.remove(idx35); // 35 제거후 35 노드의 left 노드의 idx 반환 : 30

	// print
	curr = LIST.root[0].right;
	do {
		cout << LIST.root[curr].val << " ";
		curr = LIST.root[curr].right;
	} while (LIST.root[curr].right != LIST.root[0].right);
	cout << endl;

	return 0;
}
