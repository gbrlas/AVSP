#include<stdio.h>

int main()
{
	int t,p;
	int n,i;
	int a,s,s1,sum;
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		s1=1000001;
		s=0;
		sum=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a);
			s=s^a;
			if (a<s1) s1=a;
			sum=sum+a;
		}
		if (s==0) printf("Case #%d: %d\n",p,sum-s1);
		else printf("Case #%d: NO\n",p);
	}
	return 0;
}
