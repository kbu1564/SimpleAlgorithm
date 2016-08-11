#include <iostream>
using namespace std;
int DP[1001] = { 1, 1, };
int main() {
    for (int i = 2; i < 1001; i++) {
        for (int j = 2; j * i < 1001; j++) {
            DP[j*i] = 1;
        }
    }
    int result = 0;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int NI; cin >> NI;
        if (DP[NI] == 0) result++;
    }
    cout << result << endl;
    return 0;
}