#include <cstdio>
using namespace std;
const char RST[][5] = { "No", "Yes" };
int main() {
	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) break;
		printf("%s\n", RST[a>b]);
	}
}
