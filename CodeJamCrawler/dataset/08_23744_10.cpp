#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i, n) for (int (i)=0; (i)<(n); (i)++)
#define DFOR(i, n) for (int (i)=(n)-1; (i)>=0; (i)--)
#define ALL(x) (x).begin(), (x).end()
#define SZ(s) (s).size()
#define SQR(x) ((x)*(x))
#define CLR(a) memset(a,0,sizeof(a))
#define OO 1000000000

long T, L;
bool Z[256][256][6], W[256][256][4];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	FOR(a, T)
	{
		CLR(Z); CLR(W);
		scanf("%d", &L);
		char ch[20];
		long p, x=1, y=0, X=0, Y=0, lef=0;
		FOR(b, L)
		{
			scanf("%s %d", ch, &p);
			FOR(d, p)
				for(long c = 0; ch[c]!=0; c ++)
					if (ch[c]=='R')
					{
						long tmp = x;
						x = y;
						y = -tmp;
						lef--;
					}
					else if (ch[c]=='L')
					{
						long tmp = y;
						y = x;
						x = -tmp;
						lef++;
					}
					else
					{
						if (x==1) Z[X+128][Y-1+128][2]=1;
						else if (x==-1) Z[X-1+128][Y+128][0]=1;
						else if (y==1) Z[X+128][Y+128][1]=1;
						else if (y==-1) Z[X-1+128][Y-1+128][3]=1;

						if (x==1) W[X+128][Y+128][0]=1;
						else if (x==-1) W[X-1+128][Y-1+128][2]=1;
						else if (y==1) W[X-1+128][Y+128][3]=1;
						else if (y==-1) W[X+128][Y-1+128][1]=1;
						X+=x;
						Y+=y;
					}
		}
		bool tm;
		if (lef > 0)
			FOR(c, 256) FOR(d, 256) FOR(e, 4)
				Z[c][d][e] = W[c][d][e];
		bool ss;
		FOR(c, 256)
		{
			ss=0;
			FOR(d, 256)
			{
				if (Z[c][d][0]) ss=0;
				if (ss) Z[c][d][4]=1;
				if (Z[c][d][2]) ss=1;
			}
			DFOR(d, 256)
			{
				Z[c][d][4]=0;
				if (Z[c][d][2]) break;
			}
		}
		
		FOR(c, 256)
		{
			ss=0;
			FOR(d, 256)
			{
				if (Z[d][c][1]) ss=0;
				if (ss) Z[d][c][5]=1;
				if (Z[d][c][3]) ss=1;
			}
			DFOR(d, 256)
			{
				Z[d][c][5]=0;
				if (Z[d][c][3]) break;
			}
		}
		long re=0;
		FOR(c, 256) FOR(d, 256) if (Z[d][c][5] || Z[d][c][4])
		{
			re++;
			//printf("(%d %d) ", c-128, d-128);
		}
		printf("Case #%d: %d\n", a+1, re);
	}

	return 0;
}