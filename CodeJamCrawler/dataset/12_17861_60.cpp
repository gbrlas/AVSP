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
	int i,j,wei,temp,cnt;
//	int tempA,tempB;
//	int numA[3],numB[3];
 	freopen( "C-small-attempt0.in", "r", stdin );
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
		
// 		tempA = A;
// 		tempB = B;
// 		for (k = wei-1; k >= 0; --k)
// 		{
// 			numA[k] = tempA%10;
// 			tempA /= 10;
// 			numB[k] = tempB%10;
// 			tempB /= 10;
// 		}
		if (wei == 2)
		{
			for (j = A; j < B; ++j)
			{
				temp = (j%10)*10 + j/10;
				if (temp > j && temp <= B)
				{
					++cnt;
				}
			}
		}
		else
		{
			for (j = A; j < B; ++j)
			{
				temp = (j%10)*100 + j/10;
				if (temp > j && temp <= B)
				{
					++cnt;
				}
				temp = (j%100)*10 + j/100;
				if (temp > j && temp <= B)
				{
					++cnt;
				}
			}
		}
		printf("%d\n",cnt);
	}
	
	
	return 0;
}
