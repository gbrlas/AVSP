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

#define PROBLEM_NAME "A"

const int maxn = 2005;
int len, v, r, n;
double t;
int b[maxn], e[maxn], w[maxn];
vector<pii> seg;

int main () {
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
	int TT;
	scanf ("%d", &TT);
	fori(tt, 1, TT+1) {
		printf ("Case #%d: ", tt);
		scanf ("%d%d%d%lf%d", &len, &v, &r, &t, &n);
		r -= v;
		fori(i,0,n) {
			scanf ("%d%d%d", b+i, e+i, w+i);
		}
		b[n] = len;

		seg.clear();
		if (b[0] != 0) {
			seg.pb(mp(v, b[0]-0));
		}
		fori(i,0,n) {
			seg.pb(mp((v+w[i]), e[i]-b[i]));
			if (b[i+1] != e[i]) {
				seg.pb(mp(v, b[i+1] - e[i]));
			}
		}
		sort(all(seg));
		double res = 0;
		fori(i,0,sz(seg)) {
			double v = seg[i].fi, len = seg[i].se;
			double v1 = v + r, cur = t * v1;
			if (cur >= len) {
				double t1 = len / v1;
				res += t1;
				t -= t1;
			} else {
				res += t + (len - cur) / v;
				t = 0;
			}
		}
		printf ("%.10lf\n", res);
	}
	return 0;
}
