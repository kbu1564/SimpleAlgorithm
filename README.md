# SimpleAlgorithm
Very simple and powerful algorithm
빠르면서 간단히 사용하기 편리한 알고리즘 소스 모음

## 목차
1. [Data Structure](#data-structure)
2. [Algorithm](#algorithm)
3. [Tip](#tip)

## Data Structure
1. [Circular Queue](#circular-queue)
2. [Queue & Stack](#queue--stack)

## Simple codes of Algorithm
1. [최대공약수 함수(유클리드 호제법)](#gcd)
2. [최소공배수 함수(유클리드 호제법)](#lcm)
3. [다익스트라 알고리즘 - O(E + VlogV)](#dijkstra)
4. [플로이드 워샬 알고리즘 - O(N^3)](#floyd-warshall)
5. [그래프 사이클 검사 함수(Find)](#find)
6. [합집합 수행 함수(Union)](#union)
7. [크러스컬 알고리즘](#kruskal)
8. [너비 우선 탐색(BFS)](#bfs)
9. [깊이 우선 탐색(DFS)](#dfs)
10. Network-Flow 알고리즘
11. 위상 정렬
12. [파라매트릭 서치](#parametric-search)
13. [부분 합 구하기- O(1)](#sub-sum)
14. 최장 공통 부분수열 구하기(LCS) - O(NM)
15. 최장 공통 증가 부분수열 구하기 - O(NlgN)

## Tip
1. stdio.h 함수들이 iostream 함수 보다 수십배 이상 빠름
 - 입력값으로 받아야 할 데이터의 개수가 최대 30 ~ 50만개를 넘어가는 경우 scanf, printf 함수가 훨씬 빠름
 - `cout << endl;` 보다 `cout << "\n";` 이 훨씬 빠르다.
2. stl 을 최대한 활용
3. 입력 & 출력 값을 자세히 확인후, 최대 입력값 기준으로 Big-O 계산을 통한 문제 유형 및 알고리즘 선택
4. 전역 변수가 지역변수보다 생성 가능한 배열원소의 개수가 더 많다. (보통 최대 150만개의 int 배열 생성가능)

### circular queue
```cpp
// init
const int SIZE = 100000;
int Q[SIZE];
int f = 0, r = 0;

// push
Q[r++] = 1;
r %= SIZE;

// pop
int data = Q[f++];
f %= SIZE;
```

### queue & stack
**queue**
```cpp
// init
const int SIZE = 100000;
int Q[SIZE];
int f = 0, r = 0;

// push
Q[r++] = 1;

// pop
int data = Q[f++];

// empty
bool isEmpty = (r <= f);
```

**stack**
```cpp
// init
const int SIZE = 100000;
int S[SIZE];
int t = 0;

// push
S[t++] = 1;

// pop
int data = S[--t];

// empty
bool isEmpty = (t <= 0);
```

### GCD
```cpp
int gcd(int a, int b) { return !a? b: gcd(b%a, a); }
```

### LCM
```cpp
int lcm(int a, int b) { return a / gcd(a, b) * b; }
```

### Dijkstra
```cpp
const int INF = 1e9;
const int SIZE = 20001;
const int S = 0; // 시작 노드 번호
int D[SIZE];

// 최소 우선순위 큐 지정을 위한 구조체 정의
struct node {
  int v, e;
  bool operator<(const node& n) const { return e > n.e; }
};

// 기본 모든 경로를 무한대로 셋팅
for (int i = 0; i < SIZE; i++) D[i] = INF;

// 간선 정보 셋팅
vector<node> M[SIZE];
M[5].push_back({ 1, 1 });
M[1].push_back({ 2, 2 });
M[1].push_back({ 3, 3 });
M[2].push_back({ 3, 4 });
M[2].push_back({ 4, 5 });
M[3].push_back({ 4, 6 });

// 시작점 셋팅
priority_queue<node> Q;
Q.push({ S, 0 });
D[S] = 0;
while (!Q.empty()) {
	node V = Q.top(); Q.pop();
	if (V.e > D[V.v]) continue;
	for (auto &x : M[V.v]) {
		if (D[x.v] > D[V.v] + x.e) {
			D[x.v] = D[V.v] + x.e;
			Q.push({ x.v, D[x.v] });
		}
	}
}
```

### Floyd Warshall
```cpp
// init
const int INF = 987654321;
const int N = 101;
int DP[N][N] = { 0, };
for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) DP[i][j] = INF;

// DP 행렬에 간선 정보를 입력한다.
// DP[i][j] = 정점i에서 정점j까지 가기위한 최단거리
// 
// DP[i][i] = 0;
// DP[i][j] = 만약 정점i에서 정점j까지 갈 수 없는 경우 INF;

// 방향 그래프의 경우
// 시간 복잡도 O(N^3)
//
// floyd warshall algorithm
for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		for (int k = 0; k < N; k++)
			if (DP[i][j] > DP[i][k] + DP[k][j])
				DP[i][j] = DP[i][k] + DP[k][j];

// 무방향 그래프의 경우
// 시간 복잡도 O(N^2)
//
// floyd warshall algorithm
for (int i = 0; i < N; i++)
	for (int j = i+1; j < N; j++)
		for (int k = 0; k < N; k++)
			if (DP[i][j] > DP[i][k] + DP[k][j])
				DP[j][i] = DP[i][j] = DP[i][k] + DP[k][j];
```

### Find
```cpp
int fi(int x) { return x == P[x]? x: P[x] = fi(P[x]); }

// 노드 a -> b 로 향하는 간선의 사이클 체크
// 초기화
const int SIZE = 100;                    // 노드 개수
int P[SIZE] = { 0, };
for (int i = 0; i < SIZE; i++) P[i] = i; // 자신의 부모가 자신을 가리키도록 초기화

// ... 여기에 간선 a -> b 정보가 입력되어 진다고 가정 ...

bool isCycle = (fi(a) == fi(b));         // 노드 a의 root 부모와 노드 b의 root
                                         // 부모가 같으면 사이클
```

### Union
```cpp
// 노드 x와 노드 y를 합집합 P에 추가
// 노드 x에서 노드 y로 향하는 간선 정보를 최소 스페닝 트리에 추가
void un(int x, int y) { P[fi(y)] = fi(x); }
```

### kruskal
```cpp
// P[i] = 노드i의 부모 노드번호
//             A    B    C    D    E    F    G
int  P[7] = {  0,   1,   2,   3,   4,   5,   6 };
char N[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };

// fi(), un() 함수는 위의 Find , Union 부분 참조
...

// 최소 우선순위 큐 지정을 위한 구조체 정의
struct node {
  int va, vb, e;
  bool operator<(const node& n) const { return e > n.e; }
};

// 간선 정보를 최소 우선순위 큐를 이용하여 저장
priority_queue<node> Q;

// 간선 정보 삽입
// https://ko.wikipedia.org/wiki/크러스컬_알고리즘
// va -> vb 비용 : e
Q.push({ 0, 1, 7 });
Q.push({ 0, 3, 5 });
Q.push({ 1, 2, 8 });
Q.push({ 1, 3, 9 });
Q.push({ 1, 4, 7 });
Q.push({ 2, 4, 5 });
Q.push({ 3, 4, 15 });
Q.push({ 3, 5, 6 });
Q.push({ 4, 5, 8 });
Q.push({ 5, 6, 11 });
Q.push({ 4, 6, 9 });

// 크러스컬 알고리즘 O(ElogV)
while (!Q.empty()) {
  node data = Q.top(); Q.pop();
  if (fi(data.va) != fi(data.vb)) {
    // 최소 스패닝 크리의 간선 정보 출력
    cout << N[data.va] << " -> " << N[data.vb] << " = " << data.e << endl;
    un(data.va, data.vb);
  }
}
```

### bfs
```cpp
int MAP[101][101]; // 아래와 같이 셋팅 되어있다고 가정
int VIS[101][101]; // 방문 배열
/*
MAP 정보
0 : 길
1 : 벽
(0, 0) : 출발점
(N, M) : 도착점

0 0 0 0
1 1 1 0
1 0 0 0
0 0 0 0
0 1 1 1
0 0 0 0
*/

int N = 101; // rows
int M = 101; // cols
// BFS의 탐색방식은 수면 파동과 같이 원형으로 탐색되어진다고 생각하면 이해가 조금 더 쉽다.
struct item { int x, y, c; };
const int SIZE = 100000;
const int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
item Q[SIZE];
int f = 0, r = 0;

Q[r++] = { 0, 0, 0 };
r %= SIZE;
while (f != r) {
  item data = Q[f++];
  f %= SIZE;
  VIS[data.y][data.x] = data.c;
  for (int i = 0; i < 4; i++) {
    item next = { data.x + AX[i], data.y + AY[i], data.c + 1 };
    if (next.x < 0 || next.y < 0 || next.x >= M || next.y >= N) continue;
    if (next.c > VIS[next.y][next.x]) continue;
    Q[r++] = next;
    r %= SIZE;
  }
}

cout << VIS[M][N] << endl;
```
### dfs
```cpp
int MAP[101][101]; // 아래와 같이 셋팅 되어있다고 가정
int VIS[101][101]; // 방문 배열
/*
MAP 정보
0 : 길
1 : 벽
(0, 0) : 출발점
(N, M) : 도착점

0 0 0 0
1 1 1 0
1 0 0 0
0 0 0 0
0 1 1 1
0 0 0 0
*/

int N = 101; // rows
int M = 101; // cols
// dfs의 탐색 방식은 최대한 끝까지 길을 찾아간후 잘못된 경우 되돌아가는 방식이다.
struct item { int x, y, c; };
const int SIZE = 100000;
const int AX[4] = { 0, 1, 0, -1 }, AY[4] = { -1, 0, 1, 0 };
item S[SIZE];
int t = 0;

S[t++] = { 0, 0, 0 };
while (t > 0) {
  item data = S[t++];
  VIS[data.y][data.x] = data.c;
  for (int i = 0; i < 4; i++) {
    item next = { data.x + AX[i], data.y + AY[i], data.c + 1 };
    if (next.x < 0 || next.y < 0 || next.x >= M || next.y >= N) continue;
    if (next.c > VIS[next.y][next.x]) continue;
    S[t++] = next;
  }
}

cout << VIS[M][N] << endl;
```

### Parametric Search

### Sub Sum
```cpp
// 입력이 아래와 같다고 가정한다면
int INPUT[10000] = { 0, };
for (int i = 0; i < 10000; i++) INPUT[i] = i;

int total = 0;
int SUM[10000] = { 0, };
for (int i = 0; i < 10000; i++) SUM[i] = (total += INPUT[i]);

// 5 ~ 500 까지의 합 구하기
// ans = (1 ~ 500까지 합) - (1 ~ 4까지 합);
int ans = SUM[500] - SUM[5-1];
cout << ans << endl;
```

