#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>

using namespace std;

typedef pair<int, int> PI;

char combine[26][26];
char opposed[26][26];

int main() {
	int cases;

	cin >> cases;
	for (int caseid = 1; caseid <= cases; ++caseid) {
		memset(combine, 0, sizeof(combine));
		memset(opposed, 0, sizeof(opposed));
		int C, D;
		cin >> C;
		for (int i = 0; i < C; ++i) {
			string s;
			cin >> s;
			assert( s.size() == 3 );
			combine[s[0] - 'A'][s[1] - 'A'] = combine[s[1] - 'A'][s[0] - 'A']
					= s[2];
		}
		cin >> D;
		for (int i = 0; i < D; ++i) {
			string s;
			cin >> s;
			assert( s.size() == 2 );
			opposed[s[0] - 'A'][s[1] - 'A'] = opposed[s[1] - 'A'][s[0] - 'A']
					= 1;
		}
		int n;
		string s;
		string res = "";
		cin >> n >> s;
		for (int i = 0; i < n; ++i) {
			int m = res.size();
			if (m > 0 && combine[res[m - 1] - 'A'][s[i] - 'A']) {
				res[m - 1] = combine[res[m - 1] - 'A'][s[i] - 'A'];
				continue;
			}
			int append = 1;
			for (int j = 0; j < m; ++j) {
				if (opposed[res[j] - 'A'][s[i] - 'A']) {
					res.clear();
					append = 0;
					break;
				}
			}
			if (append) {
				res += s[i];
			}
		}
		cout << "Case #" << caseid << ": [";
		for (int i = 0; i < (int) res.size(); ++i) {
			if (i > 0)
				cout << ", ";
			cout << res[i];
		}
		cout << "]\n";
	}
	return 0;
}
