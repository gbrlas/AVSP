#include<stdio.h>

int a[10001];
int l[10001];
int dp[10001][2];
int n,m;

void dfs(int x)
{
	int p,q;
	if (x<=(n-1)/2)
	{
		dfs(2*x);
		dfs(2*x+1);
		if (l[x]==1)
		{
		if (a[x]==1) p=0;
		else p=1;
		dp[x][1]=dp[2*x][1]+dp[2*x+1][1]+p;
		q=dp[2*x][0]+dp[2*x+1][0]+p;
		if (q>dp[2*x][0]+dp[2*x+1][1]+p) q=dp[2*x][0]+dp[2*x+1][1]+p;
		if (q>dp[2*x][1]+dp[2*x+1][0]+p) q=dp[2*x][1]+dp[2*x+1][0]+p;
		dp[x][0]=q;
		if (a[x]==1) p=1;
		else p=0;
		if (dp[x][0]>dp[2*x][0]+dp[2*x+1][0]+p) dp[x][0]=dp[2*x][0]+dp[2*x+1][0]+p;
		q=dp[2*x][1]+dp[2*x+1][1]+p;
		if (q>dp[2*x][0]+dp[2*x+1][1]+p) q=dp[2*x][0]+dp[2*x+1][1]+p;
		if (q>dp[2*x][1]+dp[2*x+1][0]+p) q=dp[2*x][1]+dp[2*x+1][0]+p;
		if (dp[x][1]>q) dp[x][1]=q;
		}
		else
		{
			if (a[x]==1)
			{
				dp[x][1]=dp[2*x][1]+dp[2*x+1][1];
		q=dp[2*x][0]+dp[2*x+1][0];
		if (q>dp[2*x][0]+dp[2*x+1][1]) q=dp[2*x][0]+dp[2*x+1][1];
		if (q>dp[2*x][1]+dp[2*x+1][0]) q=dp[2*x][1]+dp[2*x+1][0];
		dp[x][0]=q;
			}
			else
			{
				dp[x][0]=dp[2*x][0]+dp[2*x+1][0];
		q=dp[2*x][1]+dp[2*x+1][1];
		if (q>dp[2*x][0]+dp[2*x+1][1]) q=dp[2*x][0]+dp[2*x+1][1];
		if (q>dp[2*x][1]+dp[2*x+1][0]) q=dp[2*x][1]+dp[2*x+1][0];
		dp[x][1]=q;
			}
		}
	}
}

int main()
{
	int t,p;
	int i;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d",&n,&m);
		for (i=1;i<=(n-1)/2;i++)
			scanf("%d%d",&a[i],&l[i]);
		for (i=(n-1)/2+1;i<=n;i++)
			scanf("%d",&a[i]);
		for (i=(n-1)/2+1;i<=n;i++)
		{
			dp[i][a[i]]=0;
			dp[i][1-a[i]]=n+1;
		}
		dfs(1);
		if (dp[1][m]>(n-1)/2) printf("Case #%d: IMPOSSIBLE\n",p);
		else printf("Case #%d: %d\n",p,dp[1][m]);
	}
	return 0;
}
