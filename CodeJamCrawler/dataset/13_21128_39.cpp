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
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define RFOR(i, x, y) for(int i = x; i >= y; --i)
#define SZ(a) (int)(a).size()
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

ll R;

ll solve1(ll n, ll k)
{
	if (k == n) return n - 1;

	ll res = 0;
	ll d = n / 2;
	ll a = 2;
	while(d)
	{
		if (d < k)
		{
			res += a;
			k -= d;
		} else break;
		a *= 2;
		d /= 2;
	}
	return res;
}

int main()
{	
	// R = 4;
	// REP(i, 16) cout << solve(16, i + 1) << " " << solve1(16, i + 1) << endl;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	FOR(test, 1, tests)
	{
		ll n, p;
		cin >> n >> p;
		R = n;
		n = (1ll << n);
		printf("Case #%d: ", test); 		
		cout << solve1(n, p);
		cout << " " << max(solve1(n, p), n - 2 - solve1(n, n - p)) << endl;
	}
}