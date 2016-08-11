#include <iostream>
using namespace std;
int RESET[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int j = 0;
		int EXAM[10] = { 0, };
		for (j = 0; j < 10; j++) cin >> EXAM[j];
		for (j = 0; j < 10; j++)
			if (EXAM[j] != RESET[j])
				break;
		if (j >= 10) printf("%d\n", i+1);
	}
	return 0;
}
