#include <iostream>
#include <algorithm>
using namespace std;
// M[N][M] = N번 소가 M번 축사에 들어가기 희망하는 경우
struct node { int va, vb; };
const int SIZE = 50000;
int M[201][201];
node S[SIZE];
int main() {
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int S; cin >> S;
		for (int j = 1; j <= S; j++) {
			int Si; cin >> Si;
			M[i][Si] = 1;
		}
	}

	// network flow algorithm 구현해보기
	// 원리 이해 후 구현이 필요
	// 0 : start
	for (int i = 1; i <= N; i++) {
		int t = 0;
		S[t++] = { 0, i };
		while (t > 0) {
			node data = S[--t];
			if (data.va == 0) {
				for (int j = 1; j <= M; j++)
					if (M[data.vb][j] == 1)
						S[t++] = { data.vb, j };
			} else {
				// end
				M[data.va][data.vb] = !M[data.va][data.vb];
			}
		}
	}
	return 0;
}
