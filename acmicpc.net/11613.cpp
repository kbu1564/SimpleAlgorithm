#include <cmath>
#include <iostream>
#include <string>
using namespace std;
string OUTPUT[8] = {
	"  xxxxx  ....x  xxxxx  xxxxx  x...x  xxxxx  xxxxx  xxxxx  xxxxx  xxxxx  .....",
	"  x...x  ....x  ....x  ....x  x...x  x....  x....  ....x  x...x  x...x  ..x..",
	"  x...x  ....x  ....x  ....x  x...x  x....  x....  ....x  x...x  x...x  ..x..",
	"  x...x  ....x  xxxxx  xxxxx  xxxxx  xxxxx  xxxxx  ....x  xxxxx  xxxxx  xxxxx",
	"  x...x  ....x  x....  ....x  ....x  ....x  x...x  ....x  x...x  ....x  ..x..",
	"  x...x  ....x  x....  ....x  ....x  ....x  x...x  ....x  x...x  ....x  ..x..",
	"  xxxxx  ....x  xxxxx  xxxxx  ....x  xxxxx  xxxxx  ....x  xxxxx  xxxxx  .....",
};
int hashArr[8][6];
int HASH[11] = { 480, 224, 444, 488, 330, 468, 515, 234, 552, 505, 216 };
int main() {
	string in[8];
	for (int i = 0; i < 7; i++) cin >> in[i];

	int score = 1;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 5; j++, score++)
			hashArr[i][j] = score + j * i;

	long long N[2] = { 0, };
	int idx = 0;

	int curr = 0;
	while (curr < in[0].length()) {
		int getHashScore = 0;
		for (int i = 0; i < 7; i++)
			for (int j = curr; j < curr + 5; j++)
				if (in[i][j] == 'x')
					getHashScore += hashArr[i][j-curr];

		int getIndex = 0;
		for (int i = 0; i < 11; i++) {
			if (getHashScore == HASH[i]) {
				getIndex = i; break;
			}
		}

		char chrNum = (getIndex == 10? '+': (char)(getIndex+'0'));

		if (chrNum == '+')
			idx++;
		else
			N[idx] = N[idx] * 10 + (chrNum - '0');

		curr+=6;
	}

	string output[8];
	int skip = 1;
	long long result = N[0] + N[1];
	for (int i = 11; i >= 0; i--) {
		int n = result / (long long)pow(10, i) % 10;
		if (skip == 1 && n == 0 && i > 0) continue;
		if (n > 0) skip = 0;

		for (int y = 0; y < 7; y++) {
			for (int x = n * 7 + 2; x < n * 7 + 7; x++) output[y] += OUTPUT[y][x];
			output[y] += '.';
		}
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < output[i].length()-1; j++) putchar(output[i][j]);
		puts("");
	}
	return 0;
}
