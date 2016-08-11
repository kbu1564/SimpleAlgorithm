#include <iostream>
using namespace std;

int N;
int MAP[255][255];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b;
		int f;
		cin >> a >> b >> f;
		MAP[a][b] = f;
	}
	return 0;
}
