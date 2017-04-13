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


string s;
double dp[10000000];

double go(int mask)
{
	if (dp[mask] != 0) return dp[mask];
	int n = s.size();
	if (mask == (1 << n) - 1) return 0;

	double d = 0;	
	REP(i, n)
	{
		int x = i;
		double cur = n;
		while(mask & (1 << x))
		{
			x = (x + 1) % n;
			cur -= 1;
		}
		d += cur + go(mask + (1 << x));
	}
	double res = d / n;
	dp[mask] = res;
	return res;
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
		CLEAR(dp);
		cin >> s;
		int mask = 0;
		REP(i, s.size())
			if (s[i] == 'X') mask += (1 << i);
		printf("Case #%d: %.27lf\n", T, go(mask));
	}
}