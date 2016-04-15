# SimpleAlgorithm
Very simple and powerful algorithm

## Data Structure
1. Circular Queue

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
// data == 3
```
