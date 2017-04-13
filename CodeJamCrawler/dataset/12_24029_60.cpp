/*
 * a.cpp
 *
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

// ejp mysljylc kd kxveddknmc re jsicpdrysi
// rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
// de kr kd eoya kw aej tysr re ujdr lkgc jv

// our language is impossible to understand
// there are twenty six factorial possibilities
// so it is okay if you want to just give up


string assoc("yhesocvxduiglbkrztnwjpfmaq");

int main(void) {
	int t;
	string g;
	cin >> t;
	getline(cin, g);
	forn(i, t) {
		getline(cin, g);
		forn(j, g.size())
			if (g[j] != ' ')
				g[j] = assoc[g[j] - 'a'];
		printf("Case #%d: %s\n", i + 1, g.c_str());
	}
	return 0;
}
