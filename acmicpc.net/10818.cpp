#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N; scanf("%d", &N);

	int mini = +1000001;
	int maxi = -1000001;
	for (int i = 0; i < N; i++) {
		int NI; scanf("%d", &NI);
		if (NI < mini) mini = NI;
		if (NI > maxi) maxi = NI;
	}
	printf("%d %d\n", mini, maxi);
	return 0;
}