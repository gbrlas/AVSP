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

#define REP(i, n) for(int i = 0; i < n; ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define RFOR(i, x, y) for(int i = x; i >= y; --i)
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

int a[37];
ll n, b;

double profit(int mn, int k)
{
	REP(i, k) if (a[i] > mn) return 0;
	int s1 = 0;
	int s2 = 0;
	REP(i, k)
		s1 += mn - a[i];
	FOR(i, k, 36)
		s2 += max(0, mn + 1 - a[i]);
	if (s1 + s2 > b) return 0;
	return s1 * 36.0 / k - s1 - s2;
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
		FOR(mn, 1, 2000)
			FOR(k, 1, 36)
				res = max(res, profit(mn, k));
		printf("Case #%d: %.12lf\n", T, res);
	}
}