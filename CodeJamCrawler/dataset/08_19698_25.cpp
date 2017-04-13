#include<stdio.h>

int a[31];
int l[31];

int n,m;
int res,s;

int check(int x)
{
	if (x>(n-1)/2) return a[x];
	else
		if (a[x]==1) return check(2*x)&check(2*x+1);
		else return check(2*x)|check(2*x+1);
}

void dfs(int x)
{
	if (x==(n-1)/2+1) 
	{
		if (check(1)==m)
		{
			if (s<res) res=s;
		}
	}
	else
	{
		dfs(x+1);
		if (l[x]==1)
		{
			a[x]=1-a[x];
			s++;
			dfs(x+1);
			s--;
			a[x]=1-a[x];
		}
	}
}

int main()
{
	int t,p;
	int i;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d",&n,&m);
		for (i=1;i<=(n-1)/2;i++)
			scanf("%d%d",&a[i],&l[i]);
		for (i=(n-1)/2+1;i<=n;i++)
			scanf("%d",&a[i]);
		res=n+1;
		s=0;
		dfs(1);
		if (res==n+1) printf("Case #%d: IMPOSSIBLE\n",p);
		else printf("Case #%d: %d\n",p,res);
	}
	return 0;
}
