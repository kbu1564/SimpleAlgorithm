#include <iostream>
using namespace std;

int main() {
	char P1[3] = { 0, }, P2[3] = { 0, };
	int N;
	cin >> P1 >> P2 >> N;

	int p1x = (P1[0]-'A')+1;
	int p1y = P1[1]-'0';
	int p2x = (P2[0]-'A')+1;
	int p2y = P2[1]-'0';
	for (int i = 0; i < N; i++) {
		char MV[3] = { 0, };
		cin >> MV;
		int addx = 0, addy = 0;
		for (int j = 0; MV[j]; j++) {
			if (MV[j] == 'T') addy++;
			if (MV[j] == 'B') addy--;
			if (MV[j] == 'R') addx++;
			if (MV[j] == 'L') addx--;
		}
		if (p1x + addx < 1 || p1x + addx > 8) continue;
		if (p1y + addy < 1 || p1y + addy > 8) continue;
		p1x += addx, p1y += addy;
		if (p1x == p2x && p1y == p2y) {
			if ((p2x + addx < 1 || p2x + addx > 8) || (p2y + addy < 1 || p2y + addy > 8)) {
				p1x -= addx, p1y -= addy;
				continue;
			}
			p2x += addx, p2y += addy;
		}
	}

	cout << (char)(p1x-1+'A') << (char)(p1y+'0') << endl;
	cout << (char)(p2x-1+'A') << (char)(p2y+'0') << endl;
	return 0;
}
