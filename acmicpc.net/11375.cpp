#include <iostream>
using namespace std;

int N, M;
int WORK[1001][1001]; // WORK[i][j] = i번째 직원이 j번째 일을 할 수 있으면 1, 아니면 0
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int WN; scanf("%d", &WN);
		for (int j = 1; j <= WN; j++) {
			int work; scanf("%d", &work);
			WORK[i][work] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		
	}
	return 0;
}

