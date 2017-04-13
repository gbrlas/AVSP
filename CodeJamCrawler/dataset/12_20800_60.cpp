#include<stdio.h>

int main()
{
	int t,p;
	int n,i,j;
	int s,b;
	int a,s1,s2;
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d%d",&n,&s,&b);
		s1=0;
		s2=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if (a>=3*b-2) s1++;
			else if (a>=3*b-4) s2++;
		}
		if (s2>s) s2=s;
		if (b==0) printf("Case #%d: %d\n",p,n);
		else
			if (b==1) printf("Case #%d: %d\n",p,s1);
			else printf("Case #%d: %d\n",p,s1+s2);
	}
	return 0;
}
