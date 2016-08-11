#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int X; cin >> X;

	int result = 0;
	priority_queue< int, vector<int>, greater<int> > curr;
	int totalX = 64;
	curr.push(64);
	while (!curr.empty() && totalX > X) {
		int data = curr.top(); curr.pop();
		if (totalX - data + data / 2 >= X) {
			curr.push(data / 2);
			totalX = totalX - data + data / 2;
		} else {
			curr.push(data / 2);
			curr.push(data / 2);
		}
	}
	cout << curr.size() << endl;
	return 0;
}
