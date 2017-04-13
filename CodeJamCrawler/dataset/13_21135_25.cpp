#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <complex>
#include <ctime>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef vector< VI > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define REP(i, n) for(ll i = 0; i < n; ++i)
#define RREP(i, n) for(ll i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(ll i = x; i <= y; ++i)
#define RFOR(i, x, y) for(ll i = x; i >= y; --i)
#define SZ(a) (ll)(a).size()
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a)) 
#define CLEAR(x) memset(x, 0, sizeof x);
#define COPY(FROM, TO) memcpy(TO, FROM, sizeof TO);
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define pb push_back
#define sqr(x) (x)*(x)
#define X first
#define Y second
#define y1 Y1
#define y2 Y2
const long double pi=acos(-1.0);
const long double eps = 1e-9;

ll a[37];
ll n, b;

double profit(ll mn, ll k)
{
	REP(i, k) if (a[i] > mn) return 0;
	ll s1 = 0;
	ll s2 = 0;
	REP(i, k)
		s1 += mn - a[i];
	FOR(i, k, 36)
		s2 += max(0ll, mn + 1 - a[i]);
	if (s1 + s2 > b) return 0;
	return s1 * 36.0 / k - s1 - s2;
}

bool can(ll mn, ll k)
{
	ll s = 0;
	REP(i, k)
		s += max(0ll, mn - a[i]);
	FOR(i, k, 36)
		s += max(0ll, mn + 1 - a[i]);
	return s <= b;
}

ll find_mx(int k)
{
	if (!can(1, k)) return 0;

	ll l = 0;
	ll r = 1.0e15;
	while(l + 3 < r)
	{
		ll m = (l + r) / 2;
		if (can(m, k)) l = m;
		else r = m;
	}
	RFOR(i, r, l) if (can(i, k)) return i;
	return -1;
}

int main()
{ 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
	int tests;
	cin >> tests;
	FOR(T, 1, tests)
	{
		CLEAR(a);
		cin >> b >> n;
		REP(i, n) cin >> a[i];
		sort(a, a + 37);
		double res = 0.0;
		FOR(k, 1, 36)
		{
			ll mx = find_mx(k);
			if (mx > 0)
			{
				vector<ll> v;
				REP(i, 37)
					FOR(c, a[i] - 3, a[i] + 3)
						if (c > 0 && c <= mx)
							v.pb(c);
				FOR(c, mx - 3, mx)
					if (c > 0 && c <= mx)
						v.pb(c);
				for (ll c : v)
					res = max(res, profit(c, k));
			}			
		}		
		printf("Case #%d: %.12lf\n", (int)T, res);
	}
}