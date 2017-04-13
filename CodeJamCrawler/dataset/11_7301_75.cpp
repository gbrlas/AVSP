#include <string>	
#include <string.h>
#include <cstdio>	
#include <iostream>	
#include <memory>	
#include <cstdlib>	
#include <cmath>	
#include <algorithm>
#include <set>		
#include <map>		
#include <vector>
#include <ctime>	
#include <cassert>

using namespace std;

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define I64 "%I64d"
#else
#define I64 "%Ld"
#endif

#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define dbg(x) cerr << #x << " = " << (x) << endl
#define fori(i,b,e) for(int i = (b); i < (e); i++)
#define forall(p,s) for(typeof((s).begin()) p = (s).begin(); p != (s).end(); p++)
#define memclr(a) memset((a), 0, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define fi first
#define se second

typedef long double ldb;
typedef long long int64;
typedef pair<int,int> pii;
const int inf = (int)1e9;
ldb eps = 1e-10;

#define PROBLEM_NAME "dogs"

const int maxn = 1000;
pii a[maxn];
int n, d;

int main () {
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
	int TT;
	scanf ("%d", &TT);
	fori(tt, 1, TT+1) {
		scanf ("%d%d", &n, &d);
		fori(i,0,n) {
			scanf ("%d%d", &a[i].fi, &a[i].se);
		}
		sort(a, a+n);
		ldb l = 0, r = 1e14;
		while (r - l > 1e-7) {
			ldb t = (l + r) / 2;
			ldb cur = a[0].fi - t - 100 - d;
			bool good = true;
			fori(i,0,n) {
				cur += d;
				ldb start = max(cur, a[i].fi - t);
				ldb end = start + d * (ldb)(a[i].se - 1);
				if (end - a[i].fi > t) {
					good = false;
					break;
				}
				cur = end;
			}
			if (good) {
				r = t;
			} else {
				l = t;
			}
		}
		printf ("Case #%d: ", tt);
		printf ("%.10lf\n", (double)((l+r)/2));
	}
	return 0;
}
