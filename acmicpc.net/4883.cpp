#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int IN[100001][3];
int DP[100001][3];
int solve(int i, int p, int CK[100001][3]) {
    int rst = 0;
    if (CK[i][p] > 0) return DP[i][p];
    if (i < 0) return 0;
    if (i == 0) {
        if (p == 0)
            rst = IN[0][1];
        else if (p == 1)
            rst = IN[0][1];
        else
            rst = min(IN[0][1], IN[0][1] + IN[0][2]);
    } else {
        if (p == 0) {
            rst = IN[i][p] + min(solve(i-1, 0, CK), solve(i-1, 1, CK));
        } else if (p == 1) {
            rst = IN[i][p] + min(min(solve(i, 0, CK), solve(i-1, 0, CK)), min(solve(i-1, 1, CK), solve(i-1, 2, CK)));
        } else {
            rst = IN[i][p] + min(solve(i, 1, CK), min(solve(i-1, 1, CK), solve(i-1, 2, CK)));
        }
    }
    //cout << i << " " << p << " = " << rst << endl;
    CK[i][p] = 1;
    return DP[i][p] = rst;
}
int main() {
    int N;
    for (int i = 1; 1; i++) {
        cin >> N;
        if (N == 0) break;
        
        int CK[100001][3] = { 0, };
        for (int j = 0; j < N; j++)
            cin >> IN[j][0] >> IN[j][1] >> IN[j][2];
        
        // dp[i][p] = i번째 입력중 (p : l, v, r)의 정점까지 가기위한 최소 비용
        /*
         dp[i][l] = min(dp[i-1][l], dp[i-1][v]);
         dp[i][v] = min(dp[i][l], dp[i-1][l], dp[i-1][v], dp[i-1][r]);
         dp[i][r] = min(dp[i][v], dp[i-1][v], dp[i-1][r]);
         */
        cout << i << ". " << solve(N-1, 1, CK) << endl;
    }
    return 0;
}
/*
4
13 7 -5
7 13 6
14 3 12
15 6 16
4
13 7 -5
7 0 6
14 3 12
15 6 16
0
*/
