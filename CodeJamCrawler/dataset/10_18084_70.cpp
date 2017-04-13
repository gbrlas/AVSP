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

struct dir {
	string name;
	map <string, dir> sub;
	
	dir(string name): name(name) {}
	
	dir() {}
	
	int add(string s) {
		int pos = s.find("/");
		if(pos == -1) {
			if(!sub.count(s)) {
				sub[s] = dir(s);
				return 1;
			}
		} else {
			string a = s.substr(0, pos);
			string b = s.substr(pos + 1);
			int result = 0;
			if(!sub.count(a)) {
				sub[a] = dir(a);
				++result;
			}
			result += sub[a].add(b);
			return result;
		}
		return 0;
	}
};

int main() {
	int T, N, M;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> N >> M;
		dir root("/");
		string s;
		for(int i = 0; i < N; ++i) {
			cin >> s;
			root.add(s.substr(1));
		}
		int result = 0;
		for(int i = 0; i < M; ++i) {
			cin >> s;
			result += root.add(s.substr(1));
		}
		printf("Case #%d: %d\n", t + 1, result);
	}
}
