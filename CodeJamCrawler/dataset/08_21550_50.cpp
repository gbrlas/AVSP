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
#define INIT(a)		memset(a, 0, sizeof(a));
#define ALL(x)		(x).begin(), (x).end()
#define ABS(x)		((x) < 0 ? ((x) * (-1)) : (x))
#define PB(x)		push_back(x)

typedef vector <int>	vi;
typedef vector <double>	vd;
typedef vector <string> vs;
typedef pair <int, int>	pii;

int tc, n, m, e[2010][2010][2], use[2010];
vector < pii > v[2010];

bool check2(int p)
{
	REP(j, v[p].size())
	{
		if ( use[v[p][j].first] == v[p][j].second )
		{
			return true;
		}
	}
	return false;
}

bool check()
{
	REP(i, m)
	{
		if ( ! check2(i) )
		{
			return false;
		}
	}
	return true;
}

bool find()
{
	bool try_again = true;
	while(try_again)
	{
		if ( check() )
		{
			REP(i, n)
				printf(" %d", use[i]);
			printf("\n");
			return true;
		}
		try_again = false;
		REP(i, m)
		{
			if ( ! check2(i) )
			{
				REP(j, v[i].size())
				{
					if ( 1 == v[i][j].second )
					{
						use[v[i][j].first] = 1;
						try_again = true;
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large-out.txt", "w", stdout);

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
		INIT(use);
		printf("Case #%d:", tci + 1);
		if ( ! find() )
		{
			printf(" IMPOSSIBLE\n");
		}
	}
}
