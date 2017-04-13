//jonathanirvings template

#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
jonathan ganteng banget;

#define TEST printf("tes\n");
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);(a)++)
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);(a)--)
#define LL long long

double RPI[105],WP[105],OWP[105],OOWP[105];
int play[105][105];
int WIN[105],LOSE[105];
int n,t;
char c;

int main()
{
	scanf("%d",&t);
	FORN(cases,1,t)
	{
		printf("Case #%d:\n",cases);
		scanf("%d",&n);
		FORN(i,1,n) FORN(j,1,n) play[i][j] = 0;
		FORN(i,1,n) WIN[i] = 0, LOSE[i] = 0;
		FORN(i,1,n) 
		{
			scanf("\n");
			FORN(j,1,n)
			{
				scanf("%c",&c);
				if (c == '1') WIN[i]++, play[i][j] = 2;
				if (c == '0') LOSE[i]++, play[i][j] = 1;
			}
			WP[i] = (double)WIN[i]/(double)(WIN[i]+LOSE[i]);
		}
		FORN(i,1,n)
		{
			double owp = 0;
			int bagi = 0;
			FORN(j,1,n) if(play[i][j])
			{
				int win = WIN[j];
				int lose = LOSE[j];
				if (play[j][i] == 2) win--; else lose--;
				double tmp = (double)win/(double)(win + lose);
				owp += tmp;
				bagi++;
			}
			OWP[i] = (double)owp / (double)bagi;
		}
		FORN(i,1,n)
		{
			double oowp = 0;
			int bagi = 0;
			FORN(j,1,n) if(play[i][j])
			{
				oowp += OWP[j];
				bagi++;
			}
			OOWP[i] = (double)oowp / (double)bagi;
		}
		FORN(i,1,n)
		{
			//printf("%lf %lf %lf\n",WP[i],OWP[i],OOWP[i]);
			printf("%.13lf\n",0.25*WP[i]+0.5*OWP[i]+0.25*OOWP[i]);
		}
	}
}