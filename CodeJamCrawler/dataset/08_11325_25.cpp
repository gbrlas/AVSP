#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN=10000;

int dp[MaxN][2], val[MaxN], gate[MaxN], used[MaxN], N, V;

void readin()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &V);
	for (int i=1; i<=(N-1)/2; i++)
		scanf("%d%d", &gate[i], &used[i]);
	for (int i=(N-1)/2+1; i<=N; i++)
	{
		int x; scanf("%d", &x);
		dp[i][x]=0;
	}
}

int f(int a, int b, int kind)
{
	if (kind==0) return a|b;
	else return a&b;
}

void solve()
{
	for (int i=(N-1)/2; i>0; i--)
	{
		int x=2*i, y=2*i+1;
		for (int j=0; j<2; j++) if (dp[x][j]>=0)
			for (int k=0; k<2; k++) if (dp[y][k]>=0)
			{
				int v=f(j, k, gate[i]);
				if (dp[i][v]==-1 || dp[x][j]+dp[y][k]<dp[i][v]) dp[i][v]=dp[x][j]+dp[y][k];
				if (used[i])
				{
					v=f(j, k, 1-gate[i]);
					if (dp[i][v]==-1 || dp[x][j]+dp[y][k]+1<dp[i][v]) dp[i][v]=dp[x][j]+dp[y][k]+1;
				}
			}
	}
	if (dp[1][V]==-1) printf("IMPOSSIBLE\n");
	else printf("%d\n", dp[1][V]);
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int t; scanf("%d", &t);
	for (int step=1; step<=t; step++)
	{
		readin();
		printf("Case #%d: ", step);
		solve();
	}
	return 0;
}
