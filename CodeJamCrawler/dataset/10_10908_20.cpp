#include<iostream.h>
#include<stdio.h>
#include<math.h>

void main()
{
	int t=0;
	int r=0, k=0, n=0;
	int g[10]={0};
	long int total=0;

	scanf("%d",&t);

	for(int i=0; i<t; i++)
	{
		scanf("%d %d %d",&r, &k, &n);

		for(int j=0; j<n; j++)
		{
			scanf("%d",&g[j]);
		}

		total=0;
		int x=0;
		for(int l=0; l<r; l++)
		{
			int capacity=k;
			int y=0;

			while(y<n)
			{
				if(capacity>=g[x%n])
				{
					capacity-=g[x%n];
					total+=g[x%n];
					x++;
					y++;

				}
				else
					break;
			}

		}
		printf("Case #%d: %ld\n",(i+1), total);
	}
}