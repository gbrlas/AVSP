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

const ll MOD = 1000002013;
const int MAXN = 2000;
ll x[MAXN];
ll y[MAXN];
ll k[MAXN];
ll x1[MAXN];
ll y1[MAXN];
ll k1[MAXN];
ll N, M;
ll N1;
int order[MAXN];

#define PLL pair<ll, ll>
vector<PLL> st;

struct pt
{
	ll x, n;
	int tp;
};

bool cmp(const pt& a, const pt& b)
{
	if (a.x != b.x) return a.x < b.x;
	return a.tp < b.tp;
}
vector<pt> pts;

ll cost(ll a, ll b)
{
	ll k = b - a;
	ll r1 = (2 * N - k + 1);
	ll r2 = k;
	if (r1 % 2) r2 /= 2;
	else r1 /= 2;
	return (r1 * r2) % MOD;	
}

ll total_cost()
{
	ll res = 0;
	REP(i, M)
	{
		ll r1 = cost(x[i], y[i]);
		res += (r1 * k[i]) % MOD;
	}
	return res;
}


int main()
{	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	cin >> tests;
	FOR(test, 1, tests)
	{
		cin >> N >> M;
		pts.resize(2 * M);
		REP(i, M)
		{
			cin >> x[i] >> y[i] >> k[i];
			pts[2 * i].x = x[i]; pts[2 * i].n = k[i]; pts[2 * i].tp = 0;
			pts[2 * i + 1].x = y[i]; pts[2 * i + 1].n = k[i]; pts[2 * i + 1].tp = 1;
		}
		sort(ALL(pts), cmp);
		ll cost1 = total_cost();
		st.clear();
		N1 = 0;

		REP(i, pts.size())
		{
			if (pts[i].tp == 0)
				st.push_back(PLL(pts[i].x, pts[i].n));
			else
			{
				while(pts[i].n > 0)
				{
					int nc = min(pts[i].n, st.back().second);
					x1[N1] = st.back().first;
					y1[N1] = pts[i].x;
					k1[N1] = nc;
					++N1;
					pts[i].n -= nc;
					st.back().second -= nc;
					if (st.back().second == 0) st.pop_back();
				}
			}
		}

		M = N1;
		REP(i, M)
		{
			x[i] = x1[i];
			y[i] = y1[i];
			k[i] = k1[i];
		}
		ll cost2 = total_cost();
		ll ans = (cost1 - cost2) % MOD;
		if (ans < 0) ans += MOD;
		printf("Case #%d: ", test); 
		cout << ans << endl;
	}
}