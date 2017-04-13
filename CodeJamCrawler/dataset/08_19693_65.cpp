#include<stdio.h>
int main()
{
	int t,p;
	int k,n,i,j,a;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		printf("Case #%d:",p);
		scanf("%d",&k);
		scanf("%d",&n);
		for (j=1;j<=n;j++)
		{
			scanf("%d",&a);
			for (i=1;i<=k;i++)
			{
				a=a-i;
				while (a<0) a=a+k+1-i;
				if (a==0) break;
			}
			printf(" %d",i);
		}
		printf("\n");
	}
	return 0;
}
