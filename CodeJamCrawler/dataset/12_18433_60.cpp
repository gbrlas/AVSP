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
#include <cassert>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

string trans[4][2] = {{"a zoo", "y qee"},
	{"our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi"},
	{"there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"},
	{"so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv"}
};

char table[26];

void init() {
	memset(table, 0xff, sizeof(table));
	for(int i = 0; i < 4; ++i)
		foreach(j, 0, trans[i][0]) {
			const char from = trans[i][1][j];
			const char to = trans[i][0][j];
			if(from == ' ')
				continue;
			assert(table[from - 'a'] == -1 || table[from - 'a'] == to);
			table[from - 'a'] = to;
		}
	int unknown = 0;
	int used = 0;
	for(int i = 0; i < 26; ++i) {
		if(table[i] == -1)
			unknown = i;
		else
			used |= (1 << (table[i] - 'a'));
	}
	cerr << "unknown: " << char('a' + unknown) << " -> ?" << endl;
	cerr << "used: " << used << endl;
	for(int i = 0; i < 26; ++i)
		if(!(used & (1 << i)))
			table[unknown] = char('a' + i);
	for(int i = 0; i < 26; ++i)
		cerr << char('a' + i) << ": " << table[i] << endl;
}

int main() {
	init();
	int T;
	cin >> T;
	scanf(" ");
	for(int t = 0; t < T; ++t) {
		string s;
		getline(cin, s);
		foreach(i, 0, s)
			if(s[i] != ' ')
				s[i] = table[s[i] - 'a'];
		printf("Case #%d: %s\n", t + 1, s.c_str());
	}
	return 0;
}
