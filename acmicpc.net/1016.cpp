#include <iostream>
#include <cmath>
using namespace std;

bool PR[1000001];
bool RST[2000001];
int main() {
	long long N1, N2;
	cin >> N1 >> N2;

	for (int i = 2; i * i < 1000001; i++)
		for (int j = 2; j * i < 1000001; j++)
			PR[j*i] = true;

	for (long long i = 2; i * i <= N2; i++) {
		if (PR[i] == false) {
			// N1 보다큰 i*i로 나누어 떨어지는 수 구하기
			long long k = i*i;
			long long l = k * (N1 / k);
			if (l < N1) l += k;
			l -= N1;

			while (l <= N2-N1) {
				RST[l] = true;
				l += k;
			}
		}
	}

	int rst = 0;
	for (int i = 0; i <= N2-N1; i++) {
		if (RST[i] == false)
			rst++;
	}

	cout << rst << endl;
	return 0;
}

