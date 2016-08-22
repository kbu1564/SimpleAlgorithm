#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	while (1) {
		int BOOKLET[101][2] = { 0, };
		int N; cin >> N;
		if (N == 0) break;

		int sheetCount = N/2 + N%2;
		if (sheetCount % 2 == 1) sheetCount++;
		for (int i = 1; i <= sheetCount; i++) {
			if (i % 2 == 1) {
				BOOKLET[i][1] = i;
			}else {
				BOOKLET[i][0] = i;
			}
		}
		for (int i = sheetCount, j = sheetCount + 1; i >= 1; i--, j++) {
			if (i % 2 == 1) {
				BOOKLET[i][0] = j;
			} else {
				BOOKLET[i][1] = j;
			}
		}

		cout << "Printing order for " << N << " pages:\n";
		for (int i = 1; i <= sheetCount; i++) {
			if ((BOOKLET[i][0] == 0 || BOOKLET[i][0] > N) && (BOOKLET[i][1] == 0 || BOOKLET[i][1] > N))
				break;

			cout << "Sheet " << (i-1)/2+1 << ", " << (i % 2 == 1? "front: ": "back : ");
			if (BOOKLET[i][0] == 0 || BOOKLET[i][0] > N) cout << "Blank";
			else cout << BOOKLET[i][0];

			cout << ", ";
			if (BOOKLET[i][1] == 0 || BOOKLET[i][1] > N) cout << "Blank";
			else cout << BOOKLET[i][1];
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
