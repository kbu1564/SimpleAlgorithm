#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;
int DP[20001];
int VISIT[20001];
vector< pair<int, int> > vec[20001];
vector< pair<int, int> >::iterator iter;
struct node {
    int v;
    int w;
    bool operator<(const node& n) const { return w > n.w; }
};
int main() {
    int V, E;
    int S;
    scanf("%d %d", &V, &E);
    scanf("%d", &S);
    for (int i = 0; i < 20001; i++) DP[i] = (i == S? 0: INF);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        vec[u].push_back(pair<int, int>(v, w));
    }
    
    priority_queue<node> Q;
    Q.push({ S, DP[S] });
    
    int data = S;
    for (int i = 1; i <= E; i++) {
        if (Q.empty()) break;
        
        node datan = Q.top(); Q.pop();
        data = datan.v;
        
        if (VISIT[data] == 1) continue;
        VISIT[data] = 1;

        for (iter = vec[data].begin(); iter != vec[data].end(); iter++) {
            if (DP[iter->first] > DP[data] + iter->second) {
                DP[iter->first] = DP[data] + iter->second;
                Q.push({ iter->first, DP[iter->first] });
            }
        }
    }
    
    for (int i = 1; i <= V; i++) {
        if (DP[i] == INF) printf("INF\n");
        else printf("%d\n", DP[i]);
    }
    
    return 0;
}