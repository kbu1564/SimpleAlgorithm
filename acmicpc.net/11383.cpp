#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M; cin >> N >> M;

	string P1;
	for (int i = 0; i < N; i++) {
		string tp;
		cin >> tp;

		string ttp;
		for (int j = 0; j < tp.length(); j++) {
			ttp += tp[j];
			ttp += tp[j];
		}
		P1 += ttp;
	}

	string P2;
	for (int i = 0; i < N; i++) {
		string tp;
		cin >> tp;
		P2 += tp;
	}

	cout << (P1 == P2? "Eyfa": "Not Eyfa") << endl;
	return 0;
}
