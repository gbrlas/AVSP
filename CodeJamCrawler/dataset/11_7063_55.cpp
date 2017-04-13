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

int t,n;
typedef pair<int,int> pii;
queue <int> a;
queue <int> b;
queue <pii> task;
pii tmp2;
int posa,posb,y,tmp;
char x;

int main()
{
	freopen("bot.in","r",stdin);
	freopen("bot.out","w",stdout);
	scanf("%d",&t);
	FORN(cases,1,t)
	{
		printf("Case #%d: ",cases);
		scanf("%d",&n);
		int ans = 0;
		FORN(i,1,n)
		{
			scanf(" %c %d",&x,&y);
			tmp2.first = y;
			if (x == 'O') tmp = 1, a.push(y);
			if (x == 'B') tmp = 2, b.push(y);
			tmp2.second = tmp;
			task.push(tmp2);
		}
		posa = posb = 1;
		while (!task.empty())
		{
			//printf("%d %d %d\n",posa,posb,ans);
			tmp2 = task.front();
			if (tmp2.second == 1)
			{
				a.pop();
				int dif = abs(posa - tmp2.first) + 1;
				posa = tmp2.first;
				ans = ans + dif;
				if (!b.empty())
				{
					int target = b.front();
					int dif2 = min(dif,abs(posb - target));
					if (target > posb) posb = posb + dif2; else
						posb = posb - dif2;
				}
			}
			if (tmp2.second == 2)
			{
				b.pop();
				int dif = abs(posb - tmp2.first) + 1;
				posb = tmp2.first;
				ans = ans + dif;
				if (!a.empty())
				{
					int target = a.front();
					int dif2 = min(dif,abs(posa - target));
					if (target > posa) posa = posa + dif2; else
						posa = posa - dif2;
				}
			}
			task.pop();
		}
		printf("%d\n",ans);
	}
}