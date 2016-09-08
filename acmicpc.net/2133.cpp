#include <iostream>
#include <algorithm>
using namespace std;
/*
 ********   AA*******   AA******   A*******
 ******** = BB******* + B******* + A*******
 ********   CC*******   B*******   BB******
 f(n)   =  f(n-2)   +  g(n-1)  +  g(n-1)
 
 ********   A********   AA*******
 ******** = A******** + BB*******
  *******    ********    CC******
 g(n)   =   f(n-1)  +   g(n-2)
 
 이렇게 되면 g(n) 을 구하기 위해서 A블록이 놓여 있다면, f(n-1)의 가짓수와 같으며,
 A, B, C블록이 놓여있다면 g(n-2)의 가짓수를 구하는 것과 동일하게 되므로,
 g(n)에 대해 부분문제로 정의가 가능해 진다.
 
 마찬가지로 f(n)의 경우 A, B, C가 모두 놓인 경우에서 f(n-2)와 동일한 경우의 수가 발생되고,
 A, B를 각각 2개의 1칸을 초과하여 놓았을 경우에서는 g(n-1), g(n-2)를 구하는 것과 동일하기에,
 부분문제로 정의가 가능해 진다.
 
 따라서 점화식은 아래와 같다
 f(n) = f(n-2) + g(n-1) + g(n-1);
 g(n) = f(n-1) + g(n-2);
 */
int DP[31] = { 1, 0, 3, };
int f(int n);
int g(int n);

int f(int n) {
	if (n == 0) return 1;
	if (n == 2) return 3;
	if (DP[n] > 0) return DP[n];
	return DP[n] = f(n-2) + g(n-1) + g(n-1);
}
int g(int n) {
	if (n <= 0) return 0;
	return f(n-1) + g(n-2);
}
int main() {
	int N; cin >> N;
	cout << (N % 2 == 0? f(N): 0) << endl;
	return 0;
}
