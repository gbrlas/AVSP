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
#define INIT(a)		memset(a, 0, sizeof(a))
#define INIT1(a)		memset(a, 255, sizeof(a))
#define ALL(x)		(x).begin(), (x).end()
#define ABS(x)		((x) < 0 ? ((x) * (-1)) : (x))
#define PB(x)		push_back(x)

typedef vector <int>	vi;
typedef vector <double>	vd;
typedef vector <string> vs;
typedef pair <int, int>	pii;

int tc, n, b[10010][2], c[10010], g[10010];
unsigned mn[10010][2];

void op(int gt, int i)
{
	int x = i * 2, y = i * 2 + 1;

	if ( gt == 0 )
	{
		if ( b[x][1] && b[y][1] )
		{
			b[i][1] = 1;
			mn[i][1] = min(mn[i][1], min(mn[x][1], mn[y][1]));
		}
		if ( b[x][1] && b[y][0] )
		{
			b[i][1] = 1;
			mn[i][1] = min(mn[i][1], mn[x][1] + mn[y][0]);
		}
		if ( b[x][0] && b[y][1] )
		{
			b[i][1] = 1;
			mn[i][1] = min(mn[i][1], mn[x][0] + mn[y][1]);
		}
		if ( b[x][0] && b[y][0] )
		{
			b[i][0] = 1;
			mn[i][0] = min(mn[i][0], mn[x][0] + mn[y][0]);
		}
	}
	else
	{
		if ( b[x][1] && b[y][1] )
		{
			b[i][1] = 1;
			mn[i][1] = min(mn[i][1], mn[x][1] + mn[y][1]);
		}
		if ( b[x][1] && b[y][0] )
		{
			b[i][0] = 1;
			mn[i][0] = min(mn[i][0], mn[x][1] + mn[y][0]);
		}
		if ( b[x][0] && b[y][1] )
		{
			b[i][0] = 1;
			mn[i][0] = min(mn[i][0], mn[x][0] + mn[y][1]);
		}
		if ( b[x][0] && b[y][0] )
		{
			b[i][0] = 1;
			mn[i][0] = min(mn[i][0], min(mn[x][0], mn[y][0]));
		}
	}
	if ( c[i] )
	{
		if ( gt == 0 )
		{
			if ( b[x][1] && b[y][1] )
			{
				b[i][1] = 1;
				mn[i][1] = min(mn[i][1], mn[x][1] + mn[y][1] + 1);
			}
			if ( b[x][1] && b[y][0] )
			{
				b[i][0] = 1;
				mn[i][0] = min(mn[i][0], mn[x][1] + mn[y][0] + 1);
			}
			if ( b[x][0] && b[y][1] )
			{
				b[i][0] = 1;
				mn[i][0] = min(mn[i][0], mn[x][0] + mn[y][1] + 1);
			}
			if ( b[x][0] && b[y][0] )
			{
				b[i][0] = 1;
				mn[i][0] = min(mn[i][0], min(mn[x][0], mn[y][0]) + 1);
			}
		}
		else
		{
			if ( b[x][1] && b[y][1] )
			{
				b[i][1] = 1;
				mn[i][1] = min(mn[i][1], min(mn[x][1], mn[y][1]) + 1);
			}
			if ( b[x][1] && b[y][0] )
			{
				b[i][1] = 1;
				mn[i][1] = min(mn[i][1], mn[x][1] + mn[y][0] + 1);
			}
			if ( b[x][0] && b[y][1] )
			{
				b[i][1] = 1;
				mn[i][1] = min(mn[i][1], mn[x][0] + mn[y][1] + 1);
			}
			if ( b[x][0] && b[y][0] )
			{
				b[i][0] = 1;
				mn[i][0] = min(mn[i][0], mn[x][0] + mn[y][0] + 1);
			}
		}
	}
}

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small-out.txt", "w", stdout);

	scanf("%d", &tc);
	REP(tci, tc)
	{
		int m, v;
		vector < pii > vp;

		INIT(b);
		INIT(c);
		INIT(g);

		scanf("%d %d", &n, &v);
		m = (n - 1) / 2;
		REP(i, m)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			g[i + 1] = x;
			c[i + 1] = y;
			mn[i + 1][0] = mn[i + 1][1] = n + 1;
		}
		REP(i, (n + 1) / 2)
		{
			int x;
			scanf("%d", &x);
			b[m + i + 1][x] = 1;
			mn[m + i + 1][x] = 0;
			mn[m + i + 1][!x] = n + 1;
		}
		for( int i = m; i >= 1; --i )
		{
			op(g[i], i);
		}
		if ( b[1][v] )
			printf("Case #%d: %d\n", tci + 1, (int)mn[1][v]);
		else
			printf("Case #%d: IMPOSSIBLE\n", tci + 1);
	}
}
