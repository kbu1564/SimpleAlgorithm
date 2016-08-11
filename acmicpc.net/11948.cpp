#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int> q1, q2;
int main() {
	int a, b, c, d, e, f;
	int rst = 0;
	cin >> a >> b >> c >> d >> e >> f;
	q1.push(a); q1.push(b); q1.push(c); q1.push(d);
	q2.push(e); q2.push(f);
	rst += q1.top(); q1.pop();
	rst += q1.top(); q1.pop();
	rst += q1.top(); q1.pop();
	rst += q2.top(); q2.pop();
	cout << rst << endl;
	return 0;
}
