#include <cstdio>
#include <iostream>
using namespace std;

const size_t BUFFER_SIZE = 1100000;
char buffer[BUFFER_SIZE];
int idx = BUFFER_SIZE;

inline char readByte() {
	if (idx == BUFFER_SIZE) {
		fread(buffer, 1, BUFFER_SIZE, stdin);
		idx = 0;
	}
	return buffer[idx++];
}

inline void readInteger(int& result) {
	result = 0;
	char w = readByte();
	while (w != '\n') {
		result = result * 10 + (w - '0');
		w = readByte();
	}
}

int N, NI;
int main() {
	readInteger(N);

	long long result = 0;
	for (int i = 0; i < N; i++) {
		readInteger(NI);
		result += NI;
	}

	printf("%d\n", N);
	printf("%lld\n", result);
	return 0;
}

