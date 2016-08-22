#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	double H, P;
	while (scanf("%lf %lf", &H, &P) == 2) {
		cout << fixed;
		cout.precision(2);
		cout << H/P << endl;
	}
	return 0;
}
