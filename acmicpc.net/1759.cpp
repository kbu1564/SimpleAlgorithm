#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<char> vec;
queue< pair<int, pair<int, string> > > q;
int L, C;
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char c; cin >> c;
		vec.push_back(c);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < C; i++) {
		pair< int, pair<int, string> > result;
		result.first = 0;
		switch(vec[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				result.first++;
				break;
		}
		result.second.first = i;
		result.second.second += vec[i];
		q.push(result);
	}
	while (!q.empty()) {
		pair< int, pair<int, string> > data = q.front(); q.pop();
		if (data.second.second.length() == L && data.first > 0) {
			cout << data.second.second << "\n";
			continue;
		}
		for (int i = data.second.first + 1; i < C; i++) {
			pair< int, pair<int, string> > result;
			result.first = data.first;
			switch(vec[i]) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					result.first++;
					break;
			}
			result.second.first = i;
			result.second.second = data.second.second + vec[i];
			q.push(result);
		}
	}
	return 0;
}
