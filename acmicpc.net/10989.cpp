#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int comp(const void* a1, const void* a2) {
    return *(int*)a1 - *(int*)a2;
}
int main() {
    int N; cin >> N;
    int* ARR = new int[10000001];
    for (int i = 0; i < N; i++) scanf("%d", &ARR[i]);
    qsort(ARR, N, sizeof(int), comp);
    for (int i = 0; i < N; i++) printf("%d\n", ARR[i]);
    cout << endl;
    return 0;
}

