#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vii;

#define REP(i, n)	for( int i = 0; i < (n); ++i )
#define INIT(a)		memset(a, 0, sizeof(a))
#define INIT1(a)		memset(a, 255, sizeof(a))
#define ALL(a)		a.begin(), a.end()
#define ABS(a)		((a) < 0 ? ((a) * (-1)) : (a))

int sc[1005][105];

int main()
{
	int n, s, q;
	char line[1024];
	map < string, int > msi;

	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	scanf("%d", &n);
	REP(tc, n)
	{
		scanf("%d", &s);
		gets(line);
		REP(i, s)
		{
			gets(line);
			msi[line] = i;
		}
		scanf("%d", &q);
		gets(line);
		INIT1(sc);
		fill(sc[0], sc[0] + 105, 0);
		REP(i, q)
		{
			gets(line);
			int m = msi[line];
			REP(j, s)
			{
				if ( sc[i][j] != -1 )
				{
					REP(k, s)
					{
						if ( k != m && ( sc[i + 1][k] == -1 || sc[i + 1][k] > sc[i][j] + (j != k) ) )
						{
							sc[i + 1][k] = sc[i][j] + (j != k);
						}
					}
				}
			}
		}
		int mn = q;
		REP(i, s)
		{
			if ( sc[q][i] != -1 && sc[q][i] < mn )
				mn = sc[q][i];
		}
		printf("Case #%d: %d\n", tc + 1, mn);
	}
}
