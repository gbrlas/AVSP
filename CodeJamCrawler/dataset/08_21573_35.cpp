#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

#define REP(i, n)		for( int i = 0; i < (n); ++i )
#define INIT(a)		memset(a, 0, sizeof(a))
#define INIT1(a)		memset(a, 255, sizeof(a))
#define ALL(a)		a.begin(), a.end()

int m, n;

bool is_valid(int x)
{
	while ( x > 0 )
	{
		if ( (x & 1) && ((x >> 1) & 1) )
			return false;
		x >>= 1;
	}
	return true;
}

bool is_valid2(int x, int y, char* z)
{
	int i = n - 1;
	while ( x > 0 )
	{
		if ( (x & 1) && ( ((x >> 1) & 1) || ((y >> 1) & 1) || z[i] == 'x' ) ||
			(y & 1) && ((x >> 1) & 1) )
			return false;
		x >>= 1;
		y >>= 1;
		--i;
	}
	return true;
}

int count(int x)
{
	int c = 0;
	while ( x > 0 )
	{
		c += (x & 1);
		x >>= 1;
	}
	return c;
}

int main()
{
	freopen("c-small.txt", "r", stdin);
	freopen("c-small-out.txt", "w", stdout);

	int tc, cnt[11][1050];

	scanf("%d", &tc);
	REP(tci, tc)
	{
		scanf("%d %d", &m, &n);
		INIT(cnt);
		REP(i, m)
		{
			char temp[100];
			scanf("%s", temp);
			REP(j, 1 << n)
				if ( is_valid(j) )
					REP(k, 1 << n)
						if ( is_valid2(k, j, temp) )
							cnt[i + 1][k] = max(cnt[i + 1][k], cnt[i][j] + count(k));
		}
		int mx = 0;
		REP(i, 1 << n)
			mx = max(mx, cnt[m][i]);
		printf("Case #%d: %d\n", tci + 1, mx);
	}
}
