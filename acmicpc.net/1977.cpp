#include <iostream>
using namespace std;
long long SUM[10301];

int _mysqrt(int n) {
	int result = 1;
	while (result * result < n) result++;
	return result;
}
int main() {
	int M, N;
	cin >> M >> N;

	for (int i = 1; i * i <= 10301; i++) {
		SUM[i*i] = SUM[(i-1)*(i-1)] + i*i;
	}

	long long mm = _mysqrt(M);
	long long nn = _mysqrt(N);
	if (mm * mm > N) {
		cout << -1 << endl;
	} else {
		if (nn * nn > N) nn--;
		cout << SUM[nn*nn] - SUM[(mm-1)*(mm-1)] << endl;
		cout << mm * mm << endl;
	}
	return 0;
}
