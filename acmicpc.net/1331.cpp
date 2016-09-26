#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	bool invalid = false;
	int VIS[7][7] = { 0, };
	char MV[3]; cin >> MV;
	char ST[3] = { MV[0], MV[1], };

	int bx = MV[0]-'A'+1, by = MV[1]-'0';
	int sx = bx, sy = by;
	for (int i = 1; i < 37; i++) {
		if (i < 36)
			cin >> MV;
		else
			MV[0] = ST[0], MV[1] = ST[1];
		
		int x = MV[0]-'A'+1;
		int y = MV[1]-'0';

		int dx = abs(bx - x), dy = abs(by - y);
		if (!((dx == 1 && dy == 2) || (dx == 2 && dy == 1))) {
			//cout << bx << ", " << by << " => " << x << ", " << y << endl;
			invalid = true;
		} else {
			VIS[y][x] = 1;
		}
		bx = x, by = y;
	}
	
	int total = 0;
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			total += VIS[i][j];
	
	if (total != 36) invalid = true;
	
	cout << (invalid? "Invalid": "Valid") << endl;
	return 0;
}
