#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
double ARR[51];
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> ARR[i];

	double rst = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double c = 0;
			double x1 = i, x2 = j;
			double y1 = ARR[i], y2 = ARR[j];
			double dx = x2 - x1;
			double dy = y2 - y1;
			double dxb = y1 * dx - dy * x1;
			//cout << ARR[i] << " , " << ARR[j] << endl;
			//cout << "y = " << dy/(float)dx << "x + " << dxb/(float)dx << endl;
			for (int k = i + 1; k <= j; k++) {
				double oy = (dy * k + dxb) / dx;
				//cout << k << " = " << ARR[k] << " >? " << oy << endl;
				if (ARR[k] >= oy) break;
				c++;
			}
			cout << i << " ~ " << j << " = " << c << endl << endl;
			rst = max(rst, c);
		}
	}
	cout << rst << endl;
	return 0;
}
