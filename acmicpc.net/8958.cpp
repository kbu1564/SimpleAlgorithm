#include <iostream>
#include <string>
using namespace std;
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string S; cin >> S;

		char last = 0;
		int result = 0;
		int score = 0;
		for (int j = 0; j < S.length(); j++) {
			last = S[j];
			if (S[j] == 'O')
				score++;
			else {
				score = 0;
			}
			result += score;
		}
		cout << result << endl;
	}
	return 0;
}
