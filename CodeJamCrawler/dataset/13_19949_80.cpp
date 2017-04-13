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

bool isPalindrome(ll x) {
	ll z = 0;
	for (ll y = x; y; y /= 10)
		z = 10*z + (y % 10);
	return x == z;
}

int main() {
    //freopen("input",  "r", stdin);
    //freopen("output", "w", stdout);
    int TN;
    scanf("%d", &TN);
    FOR(TI,1,TN) {
	    ll L, R;
	    scanf("%lld%lld", &L, &R);
	    ll l = ceill(sqrtl(L));
	    ll r = floorl(sqrtl(R));
	    ll ans = 0;
	    FOR(i,l,r)
		    if (isPalindrome(i) and isPalindrome(i*i))
			    ++ans;
	    printf("Case #%d: %lld\n", TI, ans);
    }
    return 0;
}
