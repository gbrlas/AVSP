#include<stdio.h>

int gcd(int x,int y)
{
	int z;
	if (y==0) return 100;
	while (x%y!=0)
	{
		z=x%y;
		x=y;
		y=z;
	}
	return y;
}

int main()
{
	long long n;
	int pd,pg;
	int t,p;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%lld",&n);
		scanf("%d%d",&pd,&pg);
		int pp=gcd(100,pd);
		pp=100/pp;
		if (pp>n) printf("Case #%d: Broken\n",p);
		else
		{
			if (pd>0&&pg==0) printf("Case #%d: Broken\n",p);
			else
			{
				if (pd<100&&pg==100) printf("Case #%d: Broken\n",p);
				else printf("Case #%d: Possible\n",p);
			}
		}
	}
	return 0;
}
