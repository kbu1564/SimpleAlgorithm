#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<char> vec;
queue< pair< pair<int, int>, pair<int, string> > > q;
int L, C;
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char c; cin >> c;
		vec.push_back(c);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < C; i++) {
		pair< pair<int, int>, pair<int, string> > result;
		result.first.first = 0;
		result.first.second = 0;
		switch (vec[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			result.first.first++;
			break;
		default:
			result.first.second++;
			break;
		}
		result.second.first = i;
		result.second.second += vec[i];
		q.push(result);
	}
	while (!q.empty()) {
		pair< pair<int, int>, pair<int, string> > data = q.front(); q.pop();
		if (data.second.second.length() == L && data.first.first > 0 && data.first.second > 1) {
			cout << data.second.second << "\n";
			continue;
		}
		for (int i = data.second.first + 1; i < C; i++) {
			pair< pair<int, int>, pair<int, string> > result;
			result.first.first = data.first.first;
			result.first.second = data.first.second;
			switch (vec[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				result.first.first++;
				break;
			default:
				result.first.second++;
				break;
			}
			result.second.first = i;
			result.second.second = data.second.second + vec[i];
			q.push(result);
		}
	}
	return 0;
}
