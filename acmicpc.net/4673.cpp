#include <iostream>
using namespace std;
int SELF[10001];
int main() {
	for (int i = 1; i < 10001; i++) {
		int curr = i;
		int next = i;
		while (curr > 0) {
			next += curr % 10;
			curr = curr / 10;
		}
		if (next <= 10000) SELF[next]++;
	}
	for (int i = 1; i < 10001; i++)
		if (SELF[i] == 0)
			cout << i << endl;

	return 0;
}
