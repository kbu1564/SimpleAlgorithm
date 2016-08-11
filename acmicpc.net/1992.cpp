#include <iostream>
using namespace std;
const int INF = 987654321;
char M[65][65];
char RST[10001];
int idx, N;
struct pp { int x, y; };
void solve(pp s, pp e) {
    int check = 0;
    for (int i = s.y; i <= e.y; i++)
        for (int j = s.x; j <= e.x; j++)
            check += M[i][j] - M[s.y][s.x];
    
    if (check == 0 || (s.x == e.x && s.y == e.y)) {
        RST[idx++] = M[s.y][s.x];
    } else {
        pp diff = { s.x + (e.x - s.x) / 2, s.y + (e.y - s.y) / 2 };
		/*
		S--------
		|  diff  |
		 -------- E
		*/
		RST[idx++] = '(';
        solve({ s.x, s.y }, { diff.x, diff.y });
        solve({ diff.x+1, s.y }, { e.x, diff.y });
        solve({ s.x, diff.y+1 }, { diff.x, e.y });
        solve({ diff.x+1, diff.y+1 }, { e.x, e.y });
		RST[idx++] = ')';
	}
}
int main() {
	cin >> N;
    for (int i = 0; i < N; i++) cin >> M[i];
    solve({ 0, 0 }, { N-1, N-1 });
	cout << RST << endl;
	return 0;
}
