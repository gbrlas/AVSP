#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <iostream>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		char combine[26][26] = {};
		bool opposed[26][26] = {};
		int C, D, N;
		cin >> C;
		for(int i = 0; i < C; ++i) {
			string s;
			cin >> s;
			combine[s[0] - 'A'][s[1] - 'A'] = combine[s[1] - 'A'][s[0] - 'A'] = s[2] - 'A';
		}
		cin >> D;
		for(int i = 0; i < D; ++i) {
			string s;
			cin >> s;
			opposed[s[0] - 'A'][s[1] - 'A'] = opposed[s[1] - 'A'][s[0] - 'A'] = 1;
		}
		cin >> N;
		string s;
		cin >> s;
		string result;
		int have[26] = {};
		foreach(i, 0, s) {
			const char c = s[i] - 'A';
			if(result.empty()) {
				result += c;
				++have[c];
			} else if(combine[c][result[result.size() - 1]]) {
				--have[result[result.size() - 1]];
				result[result.size() - 1] = combine[c][result[result.size() - 1]];
				++have[result[result.size() - 1]];
			} else {
				for(int j = 0; j < 26; ++j)
					if(have[j] && opposed[c][j]) {
						result.clear();
						memset(have, 0, sizeof(have));
						break;
					}
				if(!result.empty()) {
					result += c;
					++have[c];
				}
			}
		}

		printf("Case #%d: [", t + 1);
		foreach(i, 0, result) {
			if(i)
				printf(", ");
			printf("%c", result[i] + 'A');
		}
		printf("]\n");
	}
	return 0;
}
