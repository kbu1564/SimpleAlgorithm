#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int a, b; scanf("%d,%d", &a, &b);
		cout << a+b << endl;
	}
	return 0;
}
