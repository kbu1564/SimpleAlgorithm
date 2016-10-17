#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1e9

using namespace std;

class Edge
{
public:
    //간선(x, y)와 가중치 w
    int x, y, w;
    Edge() {}
    Edge(int a, int b, int c)
    {
        x = a;
        y = b;
        w = c;
    }
};

long long t_res;
long long result;
int n, m, q;
vector<Edge> arr[10005];
Edge p[500001];
//부모의 번호
int parent[10005];
//높이
int height[10005];
bool visit[10005];

int cmp(const void *a, const void *b)
{
    const Edge *a1 = (const Edge *)a;
    const Edge *b1 = (const Edge *)b;

    //    return a1->w > b1->w ? 1 : -1;
    return a1->w < b1->w ? 1 : a1->w > b1->w ? -1 : 0;
}

int find(int n)
{
    //루트 값을 찾음
    if (n == parent[n])
        return n;

    return parent[n] = find(parent[n]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);

    //높이가 낮은 트리를 높이가 높은 트리의 서브트리로 합침
    if (height[x] < height[y])
        //y트리의 높이가 x트리의 높이보다 높다면,
        //높이가 낮은 x트리의 루트노드를 y로 갱신.
        parent[x] = y;
    else if (height[x] > height[y])
    {
        //x트리의 높이가 y트리의 높이보다 높다면,
        //높이가 낮은 y트리의 루트노드를 x로 갱신.
        parent[y] = x;
    }
    else if (height[x] == height[y])
    {
        //x트리의 높이가 y트리의 높이와 같다면,
        parent[y] = x;

        //높이가 같은 두개의 서브트리를 합쳤으면, 합쳐진 x트리의 높이를 1 증가시켜준다.
        if (height[x] == height[y])
            height[x]++;
    }
}
void kruskal(int n, int m)
{
    int i;
    //long long res = 0;

    //크루스칼 알고리즘은 간선을 오름차순으로 정렬한 다음 시작.
    qsort(p, m, sizeof(Edge), cmp);

    //각 정점의 부모를 본인의 값으로 초기화.
    for (i = 1; i <= n; i++)
        parent[i] = i;

    //입력받은 간선을 하나씩 확인하면서, 추가할지 않할지 선택.
    for (i = 0; i < m; i++)
    {
        int x = p[i].x;
        int y = p[i].y;

        int r1 = find(x);
        int r2 = find(y);

        //해당 간선 추가.
        if (r1 != r2)
        {
            merge(x, y);
            arr[p[i].x].push_back(Edge(p[i].x, p[i].y, p[i].w));
            arr[p[i].y].push_back(Edge(p[i].y, p[i].x, p[i].w));
        }
    }
}

int my_max(int a, int b)
{
    return a>b ? a : b;
}

int main()
{
    //freopen("input4.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);

    int test = 0;
    scanf("%d", &test);

    for (int testcase = 0; testcase < test; testcase++)
    {
        result = 0;
        n = 0, m = 0, q = 0;
        memset(p, 0, sizeof(p));
        memset(parent, 0, sizeof(parent));
        memset(height, 0, sizeof(height));

        for (int i = 0; i < 10005; i++)
            arr[i].clear();

        // 트리 정보 입력
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            p[i].x = u, p[i].y = v, p[i].w = w;
        }

        kruskal(n, m);

        scanf("%d", &q);

        for (int i = 0; i < q; i++) 
        {
            memset(visit, 0, sizeof(visit));

            int start = 0, desti = 0;
            scanf("%d %d", &start, &desti);

            t_res = 0;

            queue<Edge> q1;
            q1.push(Edge(0, start, MAX));

            while (!q1.empty()) 
            {
                Edge temp = q1.front(); 
                q1.pop();

                if (visit[temp.y] == 1) 
                    continue;

                visit[temp.y] = 1;

                //도착했으니 끝
                if (temp.y == desti) 
                {
                    t_res = temp.w;
                    break;
                }

                int ss = arr[temp.y].size();

                for (int j = 0; j < ss; j++)
                {
                    if (!visit[arr[temp.y].at(j).y])
                    {
                        q1.push(Edge(temp.y, arr[temp.y].at(j).y, min(temp.w, arr[temp.y].at(j).w)));
                    }
                }
            }

            if (t_res < MAX) 
                result += t_res;
        }

        printf("%lld\n", result);
    }

    return 0;
}