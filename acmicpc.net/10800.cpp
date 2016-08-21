#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int C[200001];
int S[2001], SUM[2001];
int DP[200001]; // DP[i] = i번째 공과 색상이 같고 크기가 같거나 큰 공의 수
vector<pair<int, int>> IN;
int main() {
	int totalSize = 0;
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int color, size; scanf("%d %d", &color, &size);
		IN.push_back(pair<int, int>(color, size));

		C[color] += size;
		S[size] += size;;

		totalSize += size;
	}

	int total = 0;
	for (int i = 0; i < 2001; i++) SUM[i] = (total += S[i]);

	for (auto v : IN) {
		int color = v.first;
		int size = v.second;

		int setABc = 0;
		for (int i = size; i < 2001; i++) setABc += DP[color][i] * i;

		int setA = totalSize - C[color];
		// setA = 색상만 다른 공의 수
		// N - C[color] = 4 - 2 = 2

		int setB = SUM[size-1];
		// setB = 크기만 작은 공의 수
		// N - SUM[size-1] = 4 - 2 = 2

		// setA와 setB의 교집합 = 색상이 다르고 && 크기가 작은 공의 수
		// setA 합집합 setB = N - 색상이 같고 크기가 같거나 큰 공의 수
		// setA + setB - ANS = setA 합집합 setB
		//
		//cout << color << " " << size << endl;
		//cout << "setA = " << setA << endl;
		//cout << "setB = " << setB << endl;
		//cout << "setA 교집합 setB = " << endl;
		cout << setA + setB - (totalSize - setABc) << endl;
	}
	return 0;
}
