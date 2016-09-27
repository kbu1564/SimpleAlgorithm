#include <iostream>
#include <queue>
using namespace std;

struct item {
	int i1, i2;
};

char S1[201];
char S2[201];
char S3[401];
int DP[201][201];

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 201; i++) for (int j = 0; j < 201; j++) DP[i][j] = 0;
		cin >> S1 >> S2 >> S3;
		
		bool possible = false;
		queue<item> Q;
		Q.push({ 0, 0 });
		while (!Q.empty()) {
			item data = Q.front(); Q.pop();
			if (DP[data.i1][data.i2] == 1) continue;
			DP[data.i1][data.i2] = 1;
			
			if (S3[data.i1 + data.i2] == 0) {
				possible = true; break;
			}
			
			if (S1[data.i1] == S3[data.i1 + data.i2]) Q.push({ data.i1 + 1, data.i2 });
			if (S2[data.i2] == S3[data.i1 + data.i2]) Q.push({ data.i1, data.i2 + 1 });
		}
		cout << "Data set " << tc << ": " << (possible? "yes": "no") << endl;
	}
	return 0;
}

