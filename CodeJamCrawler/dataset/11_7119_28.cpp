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

int n,t,a,b;
int data[105];

int main()
{
	scanf("%d",&t);
	FORN(cases,1,t)
	{
		printf("Case #%d: ",cases);
		scanf("%d %d %d",&n,&a,&b);
		FORN(i,1,n) scanf("%d",&data[i]);
		bool bisa = 0;
		FORN(i,a,b)
		{
			bool oke = 1;
			FORN(j,1,n)
			{
				if (i % data[j] != 0 && data[j] % i != 0)
				{
					oke = 0;
					break;
				}
			}
			if (oke)
			{
				bisa = 1;
				printf("%d\n",i);
				break;
			}
		}
		if (!bisa) printf("NO\n");
	}
}