#include <iostream>
using namespace std;
int main() {
	int maxPeople = 0;
	int current = 0;
	for (int i = 0; i < 10; i++) {
		int in, out; cin >> out >> in;
		current -= out;
		current += in;
		maxPeople = max(maxPeople, current);
	}
	cout << maxPeople << endl;
	return 0;
}
