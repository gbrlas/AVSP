#include<stdio.h>

int main()
{
	int t,p;
	int n,i;
	int a;
	double s;
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		s=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if (a!=i) s++;
		}
		printf("Case #%d: %.6lf\n",p,s);
	}
	return 0;
}
