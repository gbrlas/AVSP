#include <stdio.h>

void main()
{
	int n,t,i,j,check=0x0000;
	long int N[1000], sum=0, temp;

	freopen("C-large.in","r",stdin);
        freopen("output.txt","w",stdout);
	
	scanf("%d\n",&t);

	for(i=0;i<t;i++)
	{
		scanf("%d\n",&n);
		//printf("n entered");
		scanf("%ld",&N[0]);
		//printf("1st value too");
		for(j=1;j<n;j++)
			scanf(" %ld",&N[j]);
		//printf("rest of values");
		check = 0;
		for(j=0;j<n;j++)
		{
			//printf("%d ",N[j]);
			check = check^N[j];
		}
		if(check == 0)
		{
			for(j=1;j<n;j++)
			{
				if(N[j-1] < N[j])
				{
					temp = N[j-1];
					N[j-1] = N[j];
					N[j] = temp;
				}
			}
			sum = 0;
			for(j=0;j<n-1;j++)
				sum += N[j];
			printf("Case #%d: %ld\n",i+1,sum);
		}
		else
		{
			printf("Case #%d: NO\n",i+1);
		}
	}
}
