#include<stdio.h>

int main()
{
	int t,p;
	int n,i;
	int a;
	double s;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
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
