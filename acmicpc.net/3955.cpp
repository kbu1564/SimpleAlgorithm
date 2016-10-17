#include <iostream>
#include <cmath>
using namespace std;

inline int gcd(int a, int b) { return !a? b: gcd(b%a, a); }

int T, K, C;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &K, &C);
		/*
		Cx ≡ 1 (mod K)

		ax ≡ b (mod c) 일때
		a|b 이고 a|c 라면 -> x ≡ b/a (mod c/a)
		아니라면 -> x ≡ b/a (mod c)
		*/
		if (gcd(K, C) == 1) {
			long long curr = 1;
			while (curr % C != 0) curr += K;
			if (curr >= 0 && curr <= 1e9 && curr % C == 0) {
				printf("%lld\n", curr / C);
				continue;
			}
		}
		printf("IMPOSSIBLE\n");
	}
	return 0;
}

