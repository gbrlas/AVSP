#include<stdio.h>
int main()
{
	freopen("B-small.in", "r", stdin);
    freopen("B-small.txt", "w", stdout);
	long int a,b,k,i,j,l,count;
	int t,T;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		count=0;
		scanf("%ld%ld%ld",&a,&b,&k);
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				for(l=0;l<k;l++)
				{
					if((i&j)==l)
						count++;
				}
			}
		}
		printf("Case #%d: %ld\n",t,count);
	}
}
