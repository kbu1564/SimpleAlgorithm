#include <cstdio>

int main() {
	int R, C; scanf("%d %d", &R, &C);
	int minX = 0, minY = 0, minV = 1e9;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			int V; scanf("%d", &V);
			if (minV > V) {
				minX = j; minY = i;
				minV = V;
			}
		}
	}

	if (C % 2 == 1) {
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < R-1; j++) {
				if (i % 2 == 0) printf("R");
				else printf("L");
			}
			if (i < C-1) printf("D");
		}
	} else if (R % 2 == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C-1; j++) {
				if (i % 2 == 0) printf("D");
				else printf("U");
			}
			if (i < R - 1) printf("R");
		}
	} else {
	}
	printf("\n");
	return 0;
}
