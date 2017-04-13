#include <stdio.h>
#include <stdlib.h>

void main()
{
	int O[100],B[100],t,n,i,j,k,l,currO,currB,steps,step,o,b,Bn,On;
	char order[100];
	
	freopen("A-small-attempt0.in","r",stdin);
        freopen("output.txt","w",stdout);

	scanf("%d\n",&t);
	
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		Bn=0;On=0;b=0;o=0;
		for(j=0;j<n;j++)
		{
			scanf(" %c",&order[j]);
			if(order[j] == 'O')
			{
				scanf(" %d",&O[o++]);
				On++;
			}
			if(order[j] == 'B')
			{
				scanf(" %d",&B[b++]);
				Bn++;
			}
		}
		currO = 1;currB = 1;steps=0;o=0;b=0;
		for(j=0;j<n;j++)
		{
			if(order[j] == 'O')
			{
				step = abs(O[o] - currO) + 1;
				currO = O[o++];
				steps += step;
				if(currB != B[b] && b < Bn)
				{
					if(step <= abs(B[b] - currB))
					{
						if(B[b] > currB)
							currB += step;
						else
							currB -= step;
					}
					else
						currB = B[b];
				}
			}
			else
			{
				step = abs(B[b] - currB) + 1;
				currB = B[b++];
				steps += step;
				if(currO != O[o] && o < On)
				{
					if(step <= abs(O[o] - currO))
					{
						if(O[o] < currO)
							currO -= step;
						else
							currO += step;
					}
					else
						currO = O[o];
				}
			}
		}
		printf("Case #%d: %d\n",i+1,steps);
	}
}
