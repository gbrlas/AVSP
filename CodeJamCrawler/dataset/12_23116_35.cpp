#include<stdio.h>

int main()
{
	int t,s,p,n;
	int i,ctr,a,k;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d%d%d",&n,&s,&p);
		ctr=0;
		int max=3*p-3;
		int min=3*p-4;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a>max)
				ctr++;
			else if(a<min)
				continue;
			else if(s>0 && a>1)
			{
				ctr++;
				s--;
			}
		}
		printf("Case #%d: %d\n",k+1,ctr);
	}
	return 0;
	
}
