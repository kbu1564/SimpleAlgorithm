#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 987654321;
const int SIZE = 500000;
const int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
struct xy {
    int x, y, c, b;
};
char MRR[1001][1001];
int  DRR[1001][1001];
queue<xy> Q;
int main() {
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> MRR[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) DRR[i][j] = INF;
    
    int step = INF;
    Q.push({ 0, 0, 1, 0 });
    while (!Q.empty()) {
        xy data = Q.front(); Q.pop();
        if (data.b > 1) continue;
        if (data.x < 0 || data.y < 0 || data.x >= M || data.y >= N) continue;
        if (DRR[data.y][data.x] <= data.b) continue;
        if (data.x == M-1 && data.y == N-1)
            step = min(step, data.c);
        
        DRR[data.y][data.x] = data.b;
        
        for (int i = 0; i < 4; i++) {
            int x = data.x + AX[i];
            int y = data.y + AY[i];
            if (x < 0 || x >= M || y < 0 || y >= N) continue;
            if (data.b > 0 && MRR[y][x] == '1') continue;
            if (DRR[y][x] <= data.b + (MRR[y][x] == '1')) continue;
            
            Q.push({ x, y, data.c + 1, data.b + (MRR[y][x] == '1') });
        }
    }
    cout << (step >= INF? -1: step) << endl;
    return 0;
}


