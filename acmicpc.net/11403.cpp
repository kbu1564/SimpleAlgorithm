#include <iostream>
using namespace std;
int DP[101][101];
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> DP[i][j];
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (DP[i][k] == 1 && DP[k][j] == 1)
					DP[i][j] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) printf("%d ", DP[i][j]);
		printf("\n");
	}
	return 0;
}
