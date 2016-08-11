#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct water { int a, b, c; };
queue<water> Q;
int R[201];
int D[201][201][201];
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	Q.push({ 0, 0, c });
	while (!Q.empty()) {
		water data = Q.front(); Q.pop();
		// 0 0 10 -> 8 2 0 -> 0 2 8

		// 더 넣을 수 있는 물의 양
		int da = a - data.a;
		int db = b - data.b;
		int dc = c - data.c;

		if (data.a + data.b + data.c != c) continue;
		if (data.a < 0 || data.b < 0 || data.c < 0) continue;
		if (data.a > a || data.b > b || data.c > c) continue;
		if (D[data.a][data.b][data.c] > 0) continue;
		D[data.a][data.b][data.c] = 1;

		if (data.a == 0 && R[data.c] == 0) {
			R[data.c] = 1;
			//cout << da << " " << db << " " << dc << endl;
			//cout << data.a << " " << data.b << " " << data.c << endl;
		}

		Q.push({ data.a + min(data.c, da), data.b, data.c - min(data.c, da) });
		Q.push({ data.a, data.b + min(data.c, db), data.c - min(data.c, db) });

		Q.push({ data.a, data.b - min(data.b, dc), data.c + min(data.b, dc) });
		Q.push({ data.a + min(data.b, da), data.b - min(data.b, da), data.c });

		Q.push({ data.a - min(data.a, dc), data.b, data.c + min(data.a, dc) });
		Q.push({ data.a - min(data.a, db), data.b - min(data.a, db), data.c });
	}
	for (int i = 0; i < 201; i++) {
		if (R[i] > 0)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}

