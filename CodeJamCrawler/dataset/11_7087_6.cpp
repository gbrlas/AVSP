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

int t,n,pd,pg;
int PERCENT = 1000000;
int KALI = 10000;

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&t);
	FORN(cases,1,t)
	{
		printf("Case #%d: ",cases);
		scanf("%d %d %d",&n,&pd,&pg);
		pd = pd * KALI;
		pg = pg * KALI;
		bool bisa = 0;
		n++;
		while (n--)
		{
			if (n == 0) break;
			if (PERCENT % n == 0)
			{
				int a = PERCENT / n; 
				if (pd % a == 0)
				{
					int b = pd / a;
					int plays = PERCENT - n;
					int targetlose = PERCENT - pg;
					int targetwin = pg;
					int initlose = n - b;
					int initwin = b;
					int needwin = targetwin - initwin;
					int needlose = targetlose - initlose;
					if (needwin >= 0 && needlose >= 0 && needwin + needlose == plays)
					{
						bisa = 1;
						break;
					}
				}
			}
		}
		if (bisa) printf("Possible\n"); else printf("Broken\n");
	}
}