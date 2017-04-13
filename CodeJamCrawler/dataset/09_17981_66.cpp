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

string inp;
int L, D, N, result;
vector <string> xxx;

struct node {
	node *next[26];
	bool found;
	
	node() {
		memset(next, 0, sizeof(next));
		found = 0;
	}
	
	void add(string s) {
		if(s.size()) {
			if(!next[s[0] - 'a'])
				next[s[0] - 'a'] = new node();
			next[s[0] - 'a']->add(s.substr(1));
		}
	}
	
	void find(int pos/*, string s*/) {
		if(pos == L) {
			if(!found) {
				++result;
				found = true;
				//cout << "found " << s << endl;
			}
		} else {
			foreach(i, 0, xxx[pos])
				if(next[xxx[pos][i] - 'a'])
					next[xxx[pos][i] - 'a']->find(pos + 1/*, s + xxx[pos][i]*/);
		}
	}
	
	void clear() {
		found = 0;
		for(int i = 0; i < 26; ++i)
			if(next[i])
				next[i]->clear();
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin >> L >> D >> N;
	string t;
	node tree;
	for(int i = 0; i < D; ++i) {
		cin >> t;
		tree.add(t);
	}
	for(int tt = 0; tt < N; ++tt) {
		cin >> t;
		xxx.clear();
		foreach(i, 0, t) {
			xxx.push_back("");
			if(t[i] == '(') {
				++i;
				while(t[i] != ')')
					xxx.back() += t[i++];
			} else {
				xxx.back() += t[i];
			}
		}
		result = 0;
		tree.clear();
		if(xxx.size() == L)
			tree.find(0/*, ""*/);
		printf("Case #%d: %d\n", tt + 1, result);
		//cout << endl;
	}
	//system("pause");
	return 0;
}
