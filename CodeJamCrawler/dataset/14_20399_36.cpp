#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define VAR(a,b)        __typeof(b) a=(b)
#define REP(i,n)        for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b)      for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b)     for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c)   for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c)          (c).begin(),(c).end()
#define TRACE(x)        cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x)        cerr << #x << " = " << x << endl;
#define eprintf(...)    fprintf(stderr, __VA_ARGS__)

typedef long long               ll;
typedef long double             ld;
typedef unsigned long           ulong;
typedef unsigned long long      ull;
typedef vector<int>             VI;
typedef vector<vector<int> >    VVI;
typedef vector<char>            VC;

int main() {
	int tnum;
	scanf("%d", &tnum);
	FOR(ti,1,tnum) {
		ld c, f, x;
		scanf("%Lf%Lf%Lf", &c, &f, &x);
		ld ans = 1e99;
		ld dy = 0;
		ld t = 0;
		for (int n = 0; ; ++n) {
			// (2+n*f)*y-dy == x
			ans = min(ans, (x+dy)/(2+n*f));
			t = (c+dy)/(2+n*f);
			if (t > ans)
				break;
			dy = (2+n*f+f)*t;
		}
		printf("Case #%d: %.7Lf\n", ti, ans);
	}
    return 0;
}
