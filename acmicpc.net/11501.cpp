#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

namespace FIO {
	const size_t BUFFER_SIZE = 524288;
	char buffer[BUFFER_SIZE];
	char* ptr = buffer + BUFFER_SIZE;
 
	inline char readByte() {
		if (ptr == buffer + BUFFER_SIZE) {
			fread(buffer, 1, BUFFER_SIZE, stdin);
			ptr = buffer;
		}
		return *(ptr++);
	}
 
	unsigned int readUnsigned() {
		unsigned int ret = 0;
		char c = readByte();
		while (!('0' <= c && c <= '9')) {
			c = readByte();
		}
		while ('0' <= c && c <= '9') {
			ret = ret * 10 + (c - '0');
			c = readByte();
		}
		return ret;
	}
};

int t, n;
long long D[1000001];

int main() {
	t = FIO::readUnsigned();
	for (int i = 0; i < t; i++) {
		n = FIO::readUnsigned();
		
		vector<int> V[10001];
		long long sum = 0;
		for (int j = 0; j < n; j++) {
			unsigned int v = FIO::readUnsigned();
			D[j] = (sum += v);
			V[v].push_back(j);
		}
		
		int sidx = 0;
		long long gsp = 0;
		for (int j = 10000; j >= 0; j--) {
			vector<int>& v = V[j];
			int size = v.size();
			for (int k = 0; k < size; k++) {
				int jj = v[k];
				if (jj < sidx) continue;
				gsp += j * (jj - sidx) - ((jj > 0? D[jj-1]: 0LL) - (sidx > 0? D[sidx-1]: 0LL));
				sidx = jj + 1;
			}
		}
		
		printf("%lld\n", gsp < 0? 0: gsp);
	}
	return 0;
}
