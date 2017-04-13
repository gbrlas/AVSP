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

int main()
{
	freopen("d-small.in", "r", stdin);
	freopen("d-small-out.txt", "w", stdout);

	int tc, w, h, r, cnt[110][110];

	scanf("%d", &tc);
	REP(tci, tc)
	{
		scanf("%d %d %d", &h, &w, &r);
		INIT(cnt);
		cnt[0][0] = 1;
		REP(i, r)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			cnt[x - 1][y - 1] = -1;
		}
		REP(i, h)	REP(j, w)
			if ( cnt[i][j] > 0 )
			{
				int x, y;
				x = i + 2;
				y = j + 1;
				if ( x < h && y < w && cnt[x][y] != -1 )
					cnt[x][y] = (cnt[x][y] + cnt[i][j]) % 10007;
				x = i + 1;
				y = j + 2;
				if ( x < h && y < w && cnt[x][y] != -1 )
					cnt[x][y] = (cnt[x][y] + cnt[i][j]) % 10007;
			}
		printf("Case #%d: %d\n", tci + 1, cnt[h - 1][w - 1]);
	}
}
