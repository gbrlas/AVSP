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

int a[200][200];

bool check(int N, int M) {
	REP(i,N) {
		REP(j,M) {
			bool nok = true;
			REP(k,N)
				if (a[k][j] > a[i][j])
					nok = false;
			bool mok = true;
			REP(k,M)
				if (a[i][k] > a[i][j])
					mok = false;
			if (nok || mok)
				;
			else
				return false;
		}
	}
	return true;
}

int main() {
    //freopen("input",  "r", stdin);
    //freopen("output", "w", stdout);
    int TN;
    scanf("%d", &TN);
    FOR(TI,1,TN) {
	    int N, M;
	    scanf("%d%d", &N, &M);
	    REP(i,N) {
		    REP(j,M)
			    scanf("%d", &a[i][j]);
	    }
	    bool ok = check(N, M);
	    printf("Case #%d: %s\n", TI, ((ok)? "YES" : "NO"));
    }
    return 0;
}
