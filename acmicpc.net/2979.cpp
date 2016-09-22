#include <iostream>
using namespace std;
int ARR[101];
int main() {
	int M[4] = { 0, };
	cin >> M[1] >> M[2] >> M[3];
	int in, out;

	cin >> in >> out;
	for (int i = in; i < out; i++) ARR[i]++;
	cin >> in >> out;
	for (int i = in; i < out; i++) ARR[i]++;
	cin >> in >> out;
	for (int i = in; i < out; i++) ARR[i]++;

	int result = 0;
	for (int i = 0; i < 101; i++) {
		result += M[ARR[i]] * ARR[i];
	}

	cout << result << endl;
	return 0;
}
