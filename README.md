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
3. 다익스트라 알고리즘 - O(N^2) 버전
4. 다익스트라 알고리즘 - O(E + VlogV) 버전
5. 플로이드 워샬 알고리즘 - O(N^3)
6. [그래프 사이클 검사 함수(Find)](#find)
7. [합집합 수행 함수(Union)](#union)
8. 크러스컬 알고리즘
9. 너비 우선 탐색(BFS)
10. 깊이 우선 탐색(DFS)

## Tip
1. stdio.h 함수들이 iostream 함수 보다 수십배 이상 빠름
 - 입력값으로 받아야 할 데이터의 개수가 최대 30 ~ 50만개를 넘어가는 경우 scanf, printf 함수가 훨씬 빠름
2. stl 을 최대한 활용
3. 입력 & 출력 값을 자세히 확인후, 최대 입력값 기준으로 Big-O 계산을 통한 문제 유형 및 알고리즘 선택

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
