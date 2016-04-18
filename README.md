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

## Algorithm
1. 

## Tip
1. stdio.h 함수들이 iostream 함수 보다 수십배 이상 빠르다.
* 입력값으로 받아야 할 데이터의 개수가 최대 30~50만개를 넘어가는 경우 scanf, printf 함수가 훨씬 빠르다.

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

