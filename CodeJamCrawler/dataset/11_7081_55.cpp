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
int data[25];
int sum1,sum2,sum3,sum4;
char x;

int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d",&t);
	FORN(cases,1,t)
	{
		int ans = -1;
		printf("Case #%d: ",cases);
		scanf("%d",&n);
		FORN(i,0,n-1) scanf("%d",&data[i]);
		FORN(i,1,(1 << n)-2)
		{
			int coba = i;
			//printf("%d----\n",coba);
			sum1 = sum2 = sum3 = sum4 = 0;
			FORD(j,n-1,0)
			{
				if (coba >= (1 << j))
				{
					coba = coba - (1 << j);
					sum1 = sum1 ^ data[j];
					sum3 += data[j];
				} else sum2 = sum2 ^ data[j], sum4 += data[j];
				//printf("%d %d %d %d %d\n",sum1,sum2,sum3,sum4,coba);
			}
			if (sum1 == sum2)
			{
				ans = max(ans,max(sum3,sum4));
			}
		}
		if (ans == -1) printf("NO\n"); else printf("%d\n",ans);
	}
}