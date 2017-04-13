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
	for(int t = 1; t <= T; ++t) {
		string s;
		cin >> s;
		if(!next_permutation(s.begin(), s.end())) {
			sort(s.begin(), s.end());
			int zero = 1;
			while(s.size() && s[0] == '0') {
				++zero;
				s = s.substr(1);
			}
			string t;
			if(s.size()) {
				t += s[0];
				t += string(zero, '0');
				t += s.substr(1);
				s = t;
			}
		}
		cout << "Case #" << t << ": " << s << endl;
	}
	return 0;
}
