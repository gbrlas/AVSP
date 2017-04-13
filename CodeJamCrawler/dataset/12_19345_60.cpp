#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


/* Prewritten code begins */
#define PII         pair<int,int>
#define FORE(i,c)   for(VAR(i,(c).begin()); i!=(c).end(); ++i)
#define VAR(i,v)    __typeof(v) i=(v)
#define ALL(x)      (x).begin(),(x).end()
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
#define SIZE(x)     (int)(x).size()
#define PB          push_back
#define MP          make_pair
#define REP(i,n)    for(int i=0; i<(n); ++i)
#define X           first
#define Y           second
/* Prewritten code ends */

const int LIM = 2000000, maxL = 8;
vector<PII> a[maxL];
inline int s2i(const string &s) {
	int res = 0;
	FORE(i,s) res *= 10, res += *i-'0';
	return res;
}
inline void i2s(string &res, int n) {
	res = "";
	do {
		res += '0'+n%10;
		n /= 10;
	} while(n);
	reverse(ALL(res));
}
int main() {
	string s, ts;
	FOR(i,1,LIM) {
		i2s(s, i);
		int l = SIZE(s);
		FOR(p,1,l-1) {
			ts = s.substr(p)+s.substr(0,p);
			if(ts > s) {
				int t = s2i(ts);
				if(t <= LIM) a[l].PB(MP(i, t));
			}
		}
	}
	REP(i,maxL) {
		sort(ALL(a[i]));
		a[i].resize(unique(ALL(a[i]))-a[i].begin());
	}

	int T, from, to, res, len;
	cin >> T;
	FOR(cs,1,T) {
		cin >> from >> to;
		res = 0; len = (int)log10(from)+1;
		FORE(i,a[len]) if(from <= i->X && i->Y <= to) res++;
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}
