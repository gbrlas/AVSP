#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

int main( )
{
	int T,N,S,p,t;
	int i,j,cnt,resS;
 	freopen( "B-small-attempt1.in", "r", stdin );
 	freopen( "output.txt", "w", stdout );
 	scanf("%d\n",&T);
	for(i = 1; i <= T; ++i)
	{
		printf("Case #%d: ",i);
		scanf("%d",&N);
		scanf("%d",&S);
		scanf("%d",&p);
		cnt = 0;
		resS = S;
		for (j = 0; j < N; ++j)
		{
			scanf("%d",&t);
			if(t/3 >= p)
			{
				++cnt;
				continue;
			}
			if (t/3 + 2 < p)
			{
				continue;
			}
			if (t/3 + 1 == p)
			{
				if (t%3 != 0)
				{
					++cnt;
					continue;
				}
				if ((t/3 >= 1) && resS > 0)
				{
					++cnt;
					--resS;
					continue;
				}
				continue;
			}
			if ((t/3 + 2 == p) && (t%3 == 2) && resS > 0)
			{
                --resS;
				++cnt;
			}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}
