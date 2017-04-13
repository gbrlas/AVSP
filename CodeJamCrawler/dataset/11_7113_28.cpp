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

int main()
{
	int t,r,c;
	char mat[55][55];
	scanf("%d",&t);
	FORN(cases,1,t)
	{
		printf("Case #%d:\n",cases);
		scanf("%d %d",&r,&c);
		bool bisa = 1;
		FORN(i,1,r)
		{
			scanf("\n");
			FORN(j,1,c) scanf("%c",&mat[i][j]);
		}
		FORN(i,1,r)
		{
			if (!bisa) break;
			FORN(j,1,c)
			{
				if (!bisa) break;
				if (mat[i][j] == '#' && i < r && j < c)
				{
					if (mat[i][j+1] == '#' && mat[i+1][j] == '#' && mat[i+1][j+1] == '#')
					{
						mat[i][j] = '/';
						mat[i][j+1] = '\\';
						mat[i+1][j] = '\\';
						mat[i+1][j+1] = '/';
					}
					else bisa = 0;
				}
				if (mat[i][j] == '#') bisa = 0;
			}
		}
		if (!bisa) printf("Impossible\n"); else
		{
			FORN(i,1,r)
			{
				FORN(j,1,c) printf("%c",mat[i][j]);
				printf("\n");
			}
		}
	}
}