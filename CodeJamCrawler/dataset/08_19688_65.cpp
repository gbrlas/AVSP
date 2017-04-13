#include<stdio.h>
#include<string.h>

int x[101],y[101];

int main()
{
	int t,p;
	int n,m;
	long long a,b,c,d;
	long long xx,yy;
	int i,j,k,r;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%lld%lld%lld%lld%d%d%d",&n,&a,&b,&c,&d,&x[1],&y[1],&m);
		for (i=2;i<=n;i++)
		{
			x[i]=(a*x[i-1]+b)%m;
			y[i]=(c*y[i-1]+d)%m;
		}
		int res=0;
		for (i=1;i<=n;i++)
			for (j=i+1;j<=n;j++)
				for (k=j+1;k<=n;k++)
				{
					xx=x[i]+x[j]+x[k];
					yy=y[i]+y[j]+y[k];
					if (xx%3==0&&yy%3==0) res++;
				}
		printf("Case #%d: %d\n",p,res);
	}
	return 0;
}

