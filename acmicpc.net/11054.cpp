#include <iostream>
#include <algorithm>
using namespace std;

int N;
int IN[1001];

int INC[1001];
int DEC[1001];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> IN[i];

		INC[i] = 1;
		for (int j = 0; j < i; j++)
			if (IN[i] > IN[j])
				INC[i] = max(INC[i], INC[j] + 1);
	}

	for (int k = N-1; k >= 0; k--) {
		DEC[k] = 1;
		for (int l = N-1; l > k; l--)
			if (IN[k] > IN[l])
				DEC[k] = max(DEC[k], DEC[l] + 1);
	}

	//for (int i = 0; i < N; i++) cout << INC[i] << " ";
	//cout << endl;
	//for (int i = 0; i < N; i++) cout << DEC[i] << " ";
	//cout << endl;

	int result = 1;
	for (int i = 0; i < N; i++) if (DEC[i] > 1) result = max(result, INC[i] + DEC[i] - 1);
	cout << result << endl;
	return 0;
}
