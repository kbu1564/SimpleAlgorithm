#include <iostream>
#include <queue>
using namespace std;

const int Width = 6;
const int Height = 12;
int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
char MAP[Height + 1][Width + 1];
char MAP_TEMP[Height + 1][Width + 1];

struct block {
	int x, y;
	char v;
};
int main() {
	int totalBlockCount = 0;
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			cin >> MAP[i][j];
			MAP_TEMP[i][j] = MAP[i][j];
			if (MAP[i][j] != '.') totalBlockCount++;
		}
	}

	int result = 0;
	int nextTotalBlockCount = 0;
	int REMOVEW[Width + 1] = { 0, };
	int REMOVEH[Height + 1] = { 0, };
	while (totalBlockCount > 0 && nextTotalBlockCount != totalBlockCount) {
		nextTotalBlockCount = totalBlockCount;

		int VISIT[Height + 1][Width + 1] = { 0, };
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				if (VISIT[i][j]) continue;
				if (MAP[i][j] == '.') continue;

				int tmpWidth[Width + 1] = { 0, };
				int tmpHeight[Height + 1] = { 0, };
				int REMOVE[Height + 1][Width + 1] = { 0, };
