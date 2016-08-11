#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int main() {
    int N; scanf("%d", &N);
    priority_queue<long long> Q;
    for (int i = 0; i < N; i++) {
        long long A; scanf("%lld", &A);
        if (A != 0)
            Q.push(A);
        else {
            if (Q.empty()) {
								printf("0\n");
            } else {
								printf("%lld\n", Q.top());
                Q.pop();
            }
        }
    }
    return 0;
}

