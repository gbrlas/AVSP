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
#include <thread>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef vector< vector<ll> > VVI;
typedef pair<ll, ll> PII;
typedef vector<PII> VPII;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(ll i = x; i <= y; ++i)
#define RFOR(i, x, y) for(int i = x; i >= y; --i)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a)) 
#define CLEAR(x) memset(x,0,sizeof x);
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


int T;

string bs[] = {
 "11",
 "111",
 "1111",
 "11111",
 "111111",
 "1111111",
 "11111111",
 "111111111",
 "22",
 "121",
 "212",
 "11211"};

void generate(string s, vector<int> v)
{
	if (v.size() * 2 >= s.size() - 1)
	{
		string res;
		REP(i, s.size() - 1)
		{
			res.pb(s[i]);
			REP(k, v[min(i, SZ(s) - 2 - i)]) 
				res.pb('0');			
		}
		res.pb(s.back());
		if (res.size() <= 50) cout << res << endl;
		return;
	}

	REP(i, 50)
	{
		vector<int> vv = v;
		vv.pb(i);
		generate(s, vv);
	}
}

int main()
{
	freopen("numbers.txt", "w", stdout);

	REP(i, 12)
		generate(bs[i], vector<int>());
	return 0;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	FOR(TEST, 1, T)
	{
			
			printf("Case #%d: %d\n", TEST);
	}
}