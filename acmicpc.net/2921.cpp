#include <iostream>
using namespace std;
int S[1001] = { 0, };
int D[1001] = { 0, };
int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		S[i] = S[i-1] + i * (i + 1) / 2;
		D[i] = D[i-1] + (i + 1) * i;
	}
	cout << S[N] + D[N] << endl;
	return 0;
}
