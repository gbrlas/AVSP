#include<stdio.h>
#include<algorithm>

using namespace std;

struct dat
{
	double len;
	int w;
};

bool operator < (dat a, dat b)
{
	if (a.w==b.w) return a.len<b.len;
	else return a.w<b.w;
}

dat a[1010];

int main()
{
	int t,p;
	int x,s,r,n;
	double tt;
	int i,j;
	int b,c;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d%d%lf%d",&x,&s,&r,&tt,&n);
		int sum=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&b,&c);
			a[i].len=c-b;
			sum=sum+c-b;
			scanf("%d",&a[i].w);
			a[i].w=a[i].w+s;
		}
		a[0].len=x-sum;
		a[0].w=s;
		sort(a,a+n+1);
		double res=0;
		for (i=0;i<=n;i++)
			if (a[i].len/(a[i].w+r-s)<=tt)
			{
				res=res+a[i].len/(a[i].w+r-s);
				tt=tt-a[i].len/(a[i].w+r-s);
			}
			else
			{
				res=res+tt;
				a[i].len=a[i].len-tt*(a[i].w+r-s);
				break;
			}
		for (;i<=n;i++)
			res=res+a[i].len/a[i].w;
		printf("Case #%d: %.6lf\n",p,res);
	}
	return 0;
}
