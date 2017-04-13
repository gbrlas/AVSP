#include <iostream>
using namespace std;

#define lmin(a,b) a<b?a:b

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
			int tmp = lmin(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
			tmp = lmin(tmp, dp[0][l]+dp[0][r]);
			dp[0][pos] = tmp;

			if (c[pos] == 1)
			{
				tmp = lmin(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
				tmp = lmin(tmp, dp[1][l] + dp[1][r]);
				dp[1][pos] = lmin(dp[1][pos], tmp+1);
				dp[0][pos] = lmin(dp[0][pos], dp[0][l]+dp[0][r]+1);
			}
		}
		else
		{
			int tmp = lmin(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
			tmp = lmin(tmp, dp[1][l] + dp[1][r]);
			dp[1][pos] = tmp;
			dp[0][pos] = dp[0][l] + dp[0][r];

			if (c[pos] == 1)
			{
				dp[1][pos] = lmin(dp[1][pos], dp[1][l]+dp[1][r]+1);
				tmp = lmin(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
				tmp = lmin(tmp, dp[0][l]+dp[0][r]);
				dp[0][pos] = lmin(dp[0][pos], tmp+1);
			}
		}
	}
	else
	{
		dp[ g[pos] ][pos] = 0;
		dp[ 1-g[pos] ][pos] = INF;
	}

	dp[0][pos] = lmin(dp[0][pos], INF);
	dp[1][pos] = lmin(dp[1][pos], INF);
}

int solve()
{
	memset(dp, 0, sizeof(dp));
	dfs(1);
	if (dp[v][1] >= INF)
		return -1;
	return dp[v][1];
}

int main()
{
	int j, n , e =1;
	cin >> n;
	while(n--)
	{
		cin >> m >> v;
		inner = m >> 1;
		for (j=1; j<=inner; j++)
			cin >> g[j] >> c[j];
		for (; j<=m; j++)
			cin >> g[j];

		int rr = solve();
		if (rr == -1)	printf("Case #%d: IMPOSSIBLE\n", e++);
		else	printf("Case #%d: %d\n", e++, rr);
	}
	return 0;
}
