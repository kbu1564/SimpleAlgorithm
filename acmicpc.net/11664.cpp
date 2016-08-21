#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
struct point {
	int x, y, z;
};

double dist(point p1, point p2) {
	int dx = p1.x - p2.x;
	int dy = p1.y - p2.y;
	int dz = p1.z - p2.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

point P[3];
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d %d %d", &P[i].x, &P[i].y, &P[i].z);
	}

	// A-B 선분과 점C의 직교 좌표점
	int dx = P[1].x - P[0].x;
	int dy = P[1].y - P[0].x;
	int dz = P[1].z - P[0].x;
	point mid = { P[0].x + (P[1].x - P[0].x)/2.0, P[0].y + (P[1].y - P[0].x)/2.0, P[0].z + (P[1].z - P[0].z)/2.0 };

	double result = min(min(dist(P[0], P[2]), dist(P[1], P[2])), dist(mid, P[2]));
	printf("%.20lf\n", result);
	return 0;
}

