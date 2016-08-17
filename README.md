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
3. [Index Tree](#index-tree)
4. [Binary Index Tree](#binary-index-tree)

## Simple codes of Algorithm
1. [최대공약수 함수(유클리드 호제법)](#gcd)
1. [최소공배수 함수(유클리드 호제법)](#lcm)
1. [다익스트라 알고리즘 - O(E + VlogV)](#dijkstra)
1. [플로이드 워샬 알고리즘 - O(N^3)](#floyd-warshall)
1. [양방향 그래프 사이클 검사 함수(Find)](#find---undirected-graph)
1. [단방향 그래프 사이클 검사 함수(Find)](#find---directed-graph)
1. [합집합 수행 함수(Union)](#union)
1. [크러스컬 알고리즘](#kruskal)
1. [너비 우선 탐색(BFS)](#bfs)
1. [깊이 우선 탐색(DFS)](#dfs)
1. Network-Flow 알고리즘
1. 위상 정렬
1. 파라매트릭 서치
1. [부분 합 구하기- O(1)](#sub-sum)
1. 최장 공통 부분수열 구하기(LCS) - O(NM)
1. 최장 공통 증가 부분수열 구하기 - O(NlgN)
1. nCr => Combination 구하기
1. nPr => Permutation 구하기
1. 평방분할(Sqrt Decomposition)
1. [STL Sorting - O(NlogN)](#stl-sorting)
1. [Counting Sort - O(N)](#count-sorting)
1. [이분탐색 - O(logN)](#binary-search)
1. (부분 합)세그먼트 트리 - O(logN)

## Tip
1. stdio.h 함수들이 iostream 함수 보다 수십배 이상 빠름
 - 입력값으로 받아야 할 데이터의 개수가 최대 30 ~ 50만개를 넘어가는 경우 scanf, printf 함수가 훨씬 빠름
 - `cout << endl;` 보다 `cout << "\n";` 이 훨씬 빠르다.
 - 1초 안에 10만개의 int형 데이터를 입력받을 경우 cin은 '시간 초과'가 걸립니다 - acmicpc.net 기준
2. stl 을 최대한 활용
3. 입력 & 출력 값을 자세히 확인후, 최대 입력값 기준으로 Big-O 계산을 통한 문제 유형 및 알고리즘 선택
4. 전역 변수가 지역변수보다 생성 가능한 배열원소의 개수가 더 많다. (보통 최대 150만개의 int 배열 생성가능)
5. 전역공간에 선언된 변수는 로더가 프로그램 정보를 메모리에 적재시 0으로 자동 초기화를 해줍니다.
6. 보통 대회에서 문제 채점시 printf, scanf 함수는 iostream 이외에 stdio.h 헤더를 include 시켜야 컴파일이 가능합니다.
7. max, min 함수의 경우 C++ 기준으로 algorithm 헤더를 포함시키면 사용이 가능합니다.
 - std::max(), std::min();
8. Runtime Error 가 발생하는 경우의 80 ~ 90%는 배열 변수의 index 범위 초과 입니다.
9. C/C++ 에서는 double 형에 대해 10^(-13) 까지 정확도를 보장해 주지만 C++의 경우 기본 10^(-6) 에서 자동 반올림 처리합니다.
 - 소수점 단위 정확도를 요구하는 문제시 ```printf("%.20lf", double_value);``` 등의 함수를 이용하여 소수점 이하 20자리까지 표현 가능합니다.
 - printf 함수의 경우에도 소수점 단위 자동 반올림 처리 됩니다.

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

### Find - Undirected Graph
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

### Find - Directed Graph
```cpp
// 기본 원리는 DFS로 정점을 방문하는 순서대로 기억해 놓은 뒤,
// DFS 하던 도중 방문한 정점의 방문 번호가 자신의 방문번호 보다 이전에 부여된 것이면
// 역방향 간선이라 판단 가능

// 정점의 개수
const int SIZE = 10000;
// MAP[i][j] = i에서 j로 방문하기 위한 간선 비용
vector<int> MAP[SIZE];
// FIN[i] = i번 정점을 DFS 수행중이면 1 아니면 0, VIS[i] = i번 정점의 방문번호
int FIN[SIZE], VIS[SIZE];
// 순방향 사이클이 발생할 경우 1, 아니면 0
int isCycle = 0;

// 우선 VIS 배열을 사용하기 전 INF(-1) 값으로 초기화
for (int i = 0; i < 10001; i++) VIS[i] = -1;

int visitNumber = 0;
void fi(int x) {
	VIS[x] = visitNumber++;
	FIN[x] = 1;
	for (int i = 1; i <= SIZE; i++) {
		int th = MAP[x][i];

		// 이전에 방문하지 않은 정점인 경우 DFS
		if (VIS[th] != -1) fi(th);
		else if (F[th] != 0) {
			// 사이클 발생
			// 방문하기 위한 정점이 이미 DFS 진행중이면 사이클이 발생하는 것으로 간주 한다.
			isCycle = 1;
		}
	}
	FIN[x] = 0;
}
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

### STL Sorting
```cpp
// 정수를 정렬해야 할 경우 vector 랑 혼합 사용
// 작은수 -> 큰수 순서로 정렬
vector<int> vec;
vec.push_back(1);
vec.push_back(5);
vec.push_back(3);
vec.push_back(9);
vec.push_back(7);
sort(vec.begin(), vec.end());

// 만약 x, y 좌표가 들어오는데 이러한 좌표를 우선적으로 X축 정렬 후 Y축 기준 정렬을 해야할 때
// pair 이용
vector< pair<int, int> > vec;
vec.push_back(pair<int, int>(0, 0));
vec.push_back(pair<int, int>(10, 10));
vec.push_back(pair<int, int>(10, 0));
vec.push_back(pair<int, int>(0, 10));
sort(vec.begin(), vec.end());
```

### Count Sorting
```cpp
// 정렬해야 하는 데이터가 1 이상 100만 이하인 경우
int ARR[1000001];

for (int i = 0; i < N; i++) {
	int NI;
	cin >> NI;
	ARR[NI]++;
}

for (int i = 0; i < 1000001; i++) {
	if (ARR[i] <= 0) continue;

	// 해당 숫자의 개수 만큼 출력
	for (int j = 0; j < ARR[i]; j++) {
		cout << ARR[i] << " ";
	}
}
cout << endl;
```

### Binary Search
```cpp
// 전역으로 선언
int INPUT[1000001] = { 0, };

// 입력이 뒤죽박죽으로 들어오는 100만개 숫자들 중에서 M을 찾아야 할 경우
int N = 1000000;
for (int i = 0; i < N; i++)
	cin >> INPUT[i];

// 정렬 - O(NlogN)
sort(INPUT, INPUT+N);

// 존재하면 1, 존재하지 않으면 0
int M = 12345678;

// #include <algorithm> 필요
// 이분탐색 - 정렬이 된경우 O(logN)
cout << binary_search(INPUT, INPUT+N, M) << endl;
```
