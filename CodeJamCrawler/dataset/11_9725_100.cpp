#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cassert>

#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define forn(i, n) for (int i = 0; i < n; ++i)
#define foreach(i, c) for (typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

#define DEBUG

#ifdef DEBUG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

using namespace std;

typedef long long llong;

int main () {
	int T;
	cin >> T;
	forn(t, T) {
		int n;
		map<string, int> pos, time;
		cin >> n;
		int curtime = 0;
		pos["B"] = 1;
		pos["O"] = 1;
		time["B"] = 0;
		time["O"] = 0;
		forn(i, n) {
			string c;
			int k;
			cin >> c >> k;
			curtime = max(time[c] + abs(pos[c] - k) + 1, curtime + 1);
			pos[c] = k;
			time[c] = curtime;
		}
		printf("Case #%d: %d\n", t + 1, curtime);
	}

}

