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
#include <set>

using namespace std;

#define REP(i, n)		for( int i = 0; i < (n); ++i )
#define INIT(a)		memset(a, 0, sizeof(a))
#define INIT1(a)		memset(a, 255, sizeof(a))
#define ALL(a)		a.begin(), a.end()

typedef pair < int, int >	pii;


int main()
{
	freopen("a-small.txt", "r", stdin);
	freopen("a-small-out.txt", "w", stdout);

	int tc, n, t;
	char s[50];

	scanf("%d", &tc);
	REP(tci, tc)
	{
		scanf("%d", &n);
		int x = 3000, y = 3000, d = 0;
		vector < int > vl[6010], hl[6010];
		REP(i, n)
		{
			scanf("%s %d", s, &t);
			REP(j, t)	REP(k, strlen(s))
			{
				switch(s[k])
				{
				case 'F':
					switch (d)
					{
					case 0:
						vl[y].push_back(x);
						++y;
						break;
					case 1:
						hl[x].push_back(y);
						++x;
						break;
					case 2:
						--y;
						vl[y].push_back(x);
						break;
					case 3:
						--x;
						hl[x].push_back(y);
						break;
					}
					break;
				case 'L':
					d = (d + 3) % 4;
					break;
				case 'R':
					d = (d + 1) % 4;
					break;
				}
			}
		}
		set < pii > s;
		REP(i, 6002)
		{
			sort(ALL(vl[i]));
			for( int j = 1; j + 1 < vl[i].size(); j += 2 )
			{
				for( int k = vl[i][j]; k < vl[i][j + 1]; ++k )
				{
					s.insert( pii(k, i) );
				}
			}
			sort(ALL(hl[i]));
			for( int j = 1; j + 1 < hl[i].size(); j += 2 )
			{
				for( int k = hl[i][j]; k < hl[i][j + 1]; ++k )
				{
					s.insert( pii(i, k) );
				}
			}
		}
		printf("Case #%d: %d\n", tci + 1, s.size() );
	}
}
