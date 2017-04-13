#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cctype>

using namespace std;

#define ABS(x)		((x) < 0 ? ((x) * -1) : (x))
#define REP(i, n)		for( int i = 0; i < (n); ++i )
#define INIT(x)		memset(x, 0, sizeof(x))
#define INIT1(x)		memset(x, 255, sizeof(x))
#define ALL(x)		x.begin(), x.end()

typedef pair < int , int >	pii;
typedef vector < int >	vi;
typedef vector < string > vs;

int main()
{
	int tcn;
	int n, h, w;

	freopen("A-small.in", "r", stdin);
	freopen("A-small-out.txt", "w", stdout);
	scanf("%d", &tcn);
	REP(tc, tcn)
	{
		scanf("%d", &n);
		vi nh, nw, bh, bw;
		REP(i, n)
		{
			char x[100];
			scanf("%d %d %s", &h, &w, x);
			if ( x[0] == 'N' )
			{
				char temp[100];
				scanf("%s", temp);
				nh.push_back(h);
				nw.push_back(w);
			}
			else
			{
				bh.push_back(h);
				bw.push_back(w);
			}
		}
//		sort(ALL(nh));
//		sort(ALL(nw));
		sort(ALL(bh));
		sort(ALL(bw));
		bool br = false, mnnhe = false, mxnhe = false, mnnwe = false, mxnwe = false;
		int mnbh, mxbh, mnbw, mxbw;
		int mnnh, mxnh, mnnw, mxnw;
		if ( bh.size() )
		{
			br = true;
			mnbh = bh[0];
			mxbh = bh[bh.size() - 1];
			mnbw = bw[0];
			mxbw = bw[bw.size() - 1];
/*			if  ( nh.size() )
			{
				if ( nh[0] < mnbh )
				{
					mnnhe = true;
					REP(i, nh.size())
						if ( nh[i] < mnbh )
							mnnh = nh[i];
				}
				if ( nh[nh.size() - 1] > mxbh )
				{
					mxnhe = true;
					REP(i, nh.size())
						if ( nh[nh.size() - i - 1] > mxbh )
							mxnh = nh[nh.size() - i - 1];
				}
				if ( nw[0] < mnbw )
				{
					mnnwe = true;
					REP(i, nw.size())
						if ( nw[i] < mnbw )
							mnnw = nw[i];
				}
				if ( nw[nw.size() - 1] > mxbw )
				{
					mxnwe = true;
					REP(i, nw.size())
						if ( nw[nw.size() - i - 1] > mxbw )
							mxnw = nw[nw.size() - i - 1];
				}
			}*/
		}
		printf("Case #%d:\n", tc + 1);
		int m;
		scanf("%d", &m);
		REP(i, m)
		{
			scanf("%d %d", &h, &w);
			if ( br )
			{
				if ( mnbh <= h && h <= mxbh && mnbw <= w && w <= mxbw )
					printf("BIRD\n");
				else
				{
					int found = false;
					REP(j, nh.size())
					{
						if ( h <= mnbh && w <= mnbw && nh[j] <= mnbh && nw[j] <= mnbw &&
							h <= nh[j] && w <= nw[j] )
							found = true;
						if ( h <= mnbh && w >= mnbw && w <= mxbw && nh[j] <= mnbh && nw[j] >= mnbw && nw[j] <= mxbw &&
							h <= nh[j] )
							found = true;
						if ( h <= mnbh && w >= mxbw && nh[j] <= mnbh && nw[j] >= mxbw &&
							h <= nh[j] && w >= nw[j] )
							found = true;

						if ( h >= mnbh && h <= mxbh && w <= mnbw && nh[j] >= mnbh && nh[j] <= mxbh && nw[j] <= mnbw &&
							w <= nw[j] )
							found = true;
						if ( h >= mnbh && h <= mxbh && w >= mxbw && nh[j] >= mnbh && nh[j] <= mxbh && nw[j] >= mxbw &&
							w >= nw[j] )
							found = true;

						if ( h >= mxbh && w <= mnbw && nh[j] >= mxbh && nw[j] <= mnbw &&
							h >= nh[j] && w <= nw[j] )
							found = true;
						if ( h >= mxbh && w >= mnbw && w <= mxbw && nh[j] >= mxbh && nw[j] >= mnbw && nw[j] <= mxbw &&
							h >= nh[j] )
							found = true;
						if ( h >= mxbh && w >= mxbw && nh[j] >= mxbh && nw[j] >= mxbw &&
							h >= nh[j] && w >= nw[j] )
							found = true;
					}
					if ( found )
						printf("NOT BIRD\n");
					else
						printf("UNKNOWN\n");
				}
			}
			else
			{
				int found = false;
				REP(i, nh.size() )
					if ( h == nh[i] && w == nw[i] )
					{
						found = true;
					}
				if ( found )
					printf("NOT BIRD\n");
				else
					printf("UNKNOWN\n");
			}
		}
	}
}
