#include<stdio.h>
#include<string.h>

bool u[100001];
int pr[50001];

int f[100001];

int find(int x)
{
	if (f[x]==x) return f[x];
	else
	{
		f[x]=find(f[x]);
		return f[x];
	}
}

int main()
{
	int t,p;
	int i,j,l;
	long long a,b,c;
	long long r,w,jj;
	int x,y;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	memset(u,true,sizeof(u));
	l=0;
	for (i=2;i<=100000;i++)
	{
		if (u[i])
		{
			l++;
			pr[l]=i;
		}
		for (j=1;j<=l&&pr[j]<=100000/i;j++)
		{
			u[i*pr[j]]=false;
			if (i%pr[j]==0) break;
		}
	}
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		for (i=0;i<=b-a;i++)
			f[i]=i;
		for (i=1;i<=l;i++)
			if (pr[i]>=c) break;
		if (i==l+1) printf("Case #%d: %lld\n",p,b-a+1);
		else
		{
			for (;i<=l;i++)
			{
				if (a%pr[i]==0) r=a/pr[i];
				else r=a/pr[i]+1;
				w=b/pr[i];
				if (r<w)
				{
					x=find(r*pr[i]-a);
					for (jj=r+1;jj<=w;jj++)
				    {
					   y=find(jj*pr[i]-a);
					   if (x!=y) f[y]=x;
					}
				}
			}
			j=0;
			for (i=0;i<=b-a;i++)
				if (find(i)==i) j++;
			printf("Case #%d: %d\n",p,j);
		}
	}
	return 0;
}


