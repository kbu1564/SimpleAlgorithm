#include <cstdio>
#include <iostream>
using namespace std;

int MAP[101][101];
int main() {
	int R, C; scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &MAP[i][j]);
		}
	}

	int result = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int left = 1;
			for (int k = 1; k < j; k++) if (MAP[i][j] <= MAP[i][k]) {
				left = 0; break;
			}

			int right = 1;
			for (int k = j+1; k <= C; k++) if (MAP[i][j] <= MAP[i][k]) {
				right = 0; break;
			}

			int top = 1;
			for (int k = 1; k < i; k++) if (MAP[i][j] <= MAP[k][j]) {
				top = 0; break;
			}

			int bottom = 1;
			for (int k = i+1; k <= R; k++) if (MAP[i][j] <= MAP[k][j]) {
				bottom = 0; break;
			}

			result += left + right + top + bottom;
		}
	}
	printf("%d\n", result);
	return 0;
}
