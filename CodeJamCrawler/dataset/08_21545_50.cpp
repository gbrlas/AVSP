#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define REP(i, n)	for(int i = 0; i < (n); ++i)
#define FOR(i, a, b)	for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b)	for(int i = (a); i >= (b); --i)
#define ALL(x)		(x).begin(), (x).end()
#define ABS(x)		((x) < 0 ? ((x) * (-1)) : (x))
#define PB(x)		push_back(x)

typedef vector <int>	vi;
typedef vector <double>	vd;
typedef vector <string> vs;
typedef pair <int, int>	pii;

int tc, n, m, mn, use[20], ans[20];
vector < pii > v[110];

void make( int p )
{
	if ( p == n )
	{
		int invalid = 0;
		REP(i, m)
		{
			int found = 0;
			REP(j, v[i].size())
			{
				if ( use[v[i][j].first] == v[i][j].second )
				{
					found = 1;
					break;
				}
			}
			if ( found == 0 )
			{
				invalid = 1;
				break;
			}
		}
		if ( invalid == 0 )
		{
			int cnt = 0;
			REP(i, n)
				cnt += use[i];
			if ( mn > cnt )
			{
				mn = cnt;
				REP(i, n)
					ans[i] = use[i];
			}
		}
	}
	else
	{
		use[p] = 0;
		make( p + 1 );
		use[p] = 1;
		make( p + 1 );
	}
}

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("B-small-out.txt", "w", stdout);

	scanf("%d", &tc);
	REP(tci, tc)
	{
		scanf("%d %d", &n, &m);
		REP(i, m)
		{
			int t;
			v[i] = vector < pii > (0);
			scanf("%d", &t);
			REP(j, t)
			{
				int x, y;
				scanf("%d %d", &x, &y);
				v[i].push_back(pii(x - 1, y));
			}
		}
		mn = n + 1;
		make(0);
		printf("Case #%d:", tci + 1);
		if ( mn <= n )
		{
			REP(i, n)
				printf(" %d", ans[i]);
			printf("\n");
		}
		else
			printf(" IMPOSSIBLE\n");
	}
}
