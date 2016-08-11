#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
int n,k,A[101],D[10001];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  D[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = A[i]; j <= k; j++) {
      D[j] += D[j-A[i]];
    }
  }
  cout << D[k] << endl;
  return 0;
}

/*
 << 삼성 알고리즘 평가 문제 >>
 
 1. 시험실마다 감독관을 최소로 배치 가능한 최소 인원수 (총감독관, 부감독관) <- 커버 가능한 인원수 : 강의실마다 인원수 다르고, 배치해야될
    총감독관은 무조건 1명이상 드가야함, 최소 배치 가능한 감독관의 수를 구해라!
 
 2. x, y 이차원 배열 판때기에 구슬 두개가 파란 빨간 있는데 빨강을 구멍에 넣는데 상하좌우 이동가능 구멍 2개인데 파랑에 드가면 안되고 빨강만 드갈
    수 있는 최소 기울임 횟수는?
 */