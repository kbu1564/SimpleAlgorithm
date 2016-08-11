#include <iostream>
using namespace std;
struct rect {
	int x1, y1, x2, y2;
};
int M[101][105][105];
rect R[101];
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int w, h;
		cin >> R[i].x1 >> R[i].y1 >> w >> h;
		R[i].x2 = R[i].x1 + w;
		R[i].y2 = R[i].y1 + h;
		for (int y = R[i].y1; y < R[i].y2; y++)
			for (int x = R[i].x1; x < R[i].x2; x++)
				M[i][y][x] = 1;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int y = R[j].y1; y < R[j].y2; y++)
				for (int x = R[j].x1; x < R[j].x2; x++)
					if (M[i][y][x] == 1)
						M[i][y][x] = 0;
		}

		int result = 0;
		for (int y = 0; y < 105; y++) for (int x = 0; x < 105; x++) if (M[i][y][x] == 1) result++;
		cout << result << endl;
	}
	return 0;
}
