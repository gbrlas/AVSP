
#include <vector>
#include<iostream>
using namespace std;

const int MMAX = 11000;
const int INF = 20000;
int m, v;
int g[MMAX], c[MMAX];
int inner;
int dp[2][MMAX];

void dfs(int pos)
{
	int l = pos<<1;
	int r = l + 1;
	if (pos <= inner)
	{
		dfs(l);
		dfs(r);
		if (g[pos] == 1)
		{
			dp[1][pos] = dp[1][l] + dp[1][r];
			int tmp = min(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
			tmp = min(tmp, dp[0][l]+dp[0][r]);
			dp[0][pos] = tmp;

			if (c[pos] == 1)
			{
				tmp = min(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
				tmp = min(tmp, dp[1][l] + dp[1][r]);
				dp[1][pos] = min(dp[1][pos], tmp+1);
				dp[0][pos] = min(dp[0][pos], dp[0][l]+dp[0][r]+1);
			}
		}
		else
		{
			int tmp = min(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
			tmp = min(tmp, dp[1][l] + dp[1][r]);
			dp[1][pos] = tmp;
			dp[0][pos] = dp[0][l] + dp[0][r];

			if (c[pos] == 1)
			{
				dp[1][pos] = min(dp[1][pos], dp[1][l]+dp[1][r]+1);
				tmp = min(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
				tmp = min(tmp, dp[0][l]+dp[0][r]);
				dp[0][pos] = min(dp[0][pos], tmp+1);
			}
		}
	}
	else
	{
		dp[ g[pos] ][pos] = 0;
		dp[ 1-g[pos] ][pos] = INF;
	}

	dp[0][pos] = min(dp[0][pos], INF);
	dp[1][pos] = min(dp[1][pos], INF);
}

int solve()
{
	int i, j;

	memset(dp, 0, sizeof(dp));
	dfs(1);
	if (dp[v][1] >= INF)return -1;
	return dp[v][1];
}

int main()
{
	int i, j, n;
	freopen("d://A-small-attempt0.in", "r", stdin);
	freopen("d://A-small-attempt0.out", "w", stdout);
	scanf("%d",&n);
	for (i=1; i<=n; i++)
	{
		scanf("%d%d",&m,&v);
		inner = m >> 1;
		for (j=1; j<=inner; j++)
			scanf("%d%d",&g[j],&c[j]);
		for (; j<=m; j++)scanf("%d",&g[j]);
		int ret = solve();
		if (ret == -1)
			printf("Case #%d: IMPOSSIBLE\n", i);
		else
			printf("Case #%d: %d\n", i, ret);
	}
}
