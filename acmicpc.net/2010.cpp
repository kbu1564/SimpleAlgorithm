#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	int totalSum = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int NI; cin >> NI;
		totalSum += NI;
	}
	totalSum -= N - 1;
	cout << totalSum << endl;
	return 0;
}
