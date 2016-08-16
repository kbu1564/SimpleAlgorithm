#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int X[1001], Y[1001];
int main() {
	for (int i = 0; i < 3; i++) {
		int xi, yi; cin >> xi >> yi;
		X[xi]++; Y[yi]++;
	}
	int px = 0;
	int py = 0;
	for (int i = 0; i < 1001; i++) {
		if (X[i] == 1) px = i;
		if (Y[i] == 1) py = i;
	}
	cout << px << " " << py << endl;
	return 0;
}