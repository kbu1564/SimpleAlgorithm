#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char DIG[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
char get(char str[501], int s) {
	int rst = 0;
	for (int i = s; i < s + 2; i++) {
		if (str[i] == 0) break;
		int num = 0;
		for (int j = 0; j < 16; j++) {
			if (str[i] == DIG[j]) {
				num = j;
				break;
			}
		}
		rst = rst * 16 + num;
	}
	return rst;
}
int main() {
	char str[501];
	for (int i = 0; i < 1000 && scanf("%s", str) == 1; i++) {
		int len = strlen(str);
		for (int j = 0; j < len; j+=2)
			printf("%c", get(str, j));
		printf("\n");
	}
	return 0;
}
