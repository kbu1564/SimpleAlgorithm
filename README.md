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
1. 최대공약수 함수(유클리드 호제법)
2. 최소공배수 함수(유클리드 호제법)
3. 다익스트라 알고리즘 - O(N^2) 버전
4. 다익스트라 알고리즘 - O(E + VlogV) 버전
5. 플로이드 워샬 알고리즘 - O(N^3)
6. 그래프 사이클 검사 함수(Find)
7. 합집합 수행 함수(Union)
8. 크러스컬 알고리즘
9. 너비 우선 탐색(BFS)
10. 깊이 우선 탐색(DFS)

## Tip
1. stdio.h 함수들이 iostream 함수 보다 수십배 이상 빠름
 - 입력값으로 받아야 할 데이터의 개수가 최대 30 ~ 50만개를 넘어가는 경우 scanf, printf 함수가 훨씬 빠름
2. stl 을 최대한 활용
3. 입력 & 출력 값을 자세히 확인후, 최대 입력값 기준으로 Big-O 계산을 통한 문제 유형 및 알고리즘 선택

### circular queue
**init**
```cpp
const int SIZE = 100000;
int Q[SIZE];
int f = 0, r = 0;
```

**push**
```cpp
Q[r++] = 1;
r %= SIZE;
```

**pop**
```cpp
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

