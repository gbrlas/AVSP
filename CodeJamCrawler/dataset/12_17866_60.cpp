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
	int T,A,B;
	int div,mul;
	int i,j,k,wei,temp,cnt;
 	freopen( "C-large.in", "r", stdin );
 	freopen( "output.txt", "w", stdout );
 	scanf("%d\n",&T);
	for(i = 1; i <= T; ++i)
	{
		scanf("%d%d",&A,&B);
		printf("Case #%d: ",i);
		wei = 0;
		cnt = 0;
		temp = A;
		if (B/10 == 0 || A == B)
		{
			printf("0\n");
			continue;
		}
		while (temp)
		{
			temp /= 10;
			++wei;
		}
		for (j = A; j < B; ++j)
		{
            for(k = 1; k < wei; ++k)
            {
                  div = (int)floor(pow(10,k)+0.5);
                  mul = (int)floor(pow(10,wei-k)+0.5);
                  temp = (j%div)*mul + j/div;
                  if(temp == j)
                          break;
                  if(temp > j && temp <= B)
                  {
                          ++cnt;
                  }
            }
		}
		
		printf("%d\n",cnt);
	}
	
	
	return 0;
}
