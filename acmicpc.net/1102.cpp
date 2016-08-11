#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct battery {
	int i, int v;
	bool operator < (const battery& b) { return v > b.v; }
};
vector<int> VRR[17]; // i번 발전소를 이용하여 vector:j번 발전소를 고치기 위한 비용
priority_queue<battery> Q[17];  // idx번 발전소를 고치기 위해 필요한 비용의 Min-Queue
priority_queue<battery> Y[17]; // 가동중인 idx번 발전소의 j 발전소를 고치기 위한 비용 정보
priority_queue<battery> N[17]; // 고쳐야 할 idx번 발전소의 j 발전소를 고치기 위한 비용 정보
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int v; cin >> v;
			VRR[i].push_back(v);
		}
	}

	for (int i = 0; i < N; i++) {
		char yn; cin >> yn;
		for (int j = 0; j < N; j++) {
			if (yn == 'Y') Y[j].push_back({ i, VRR[i][j] });
			if (yn == 'N') N[j].push_back({ i, VRR[i][j] });
		}
	}
	int P; cin >> P;

	return 0;
}
