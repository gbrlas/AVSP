#include <iostream>

using namespace std;
#define OO 1000000000

long N;
long M, V;
bool O[10010];
bool C[10010];
long dp[10010][2];

long F(long x, long a, long b)
{
	return dp[x*2][a]+dp[x*2+1][b];
}

void Dp(long x)
{
	if (O[x])
	{
		dp[x][1] = min(dp[x][1], F(x, 1, 1));
		dp[x][0] = min(dp[x][0], min(F(x, 0, 0), min(F(x, 0, 1), F(x, 1, 0))));
		if (C[x])
		{
			dp[x][0] = min(dp[x][0], F(x, 0, 0)+1);
			dp[x][1] = min(dp[x][1], min(F(x, 1, 1), min(F(x, 0, 1), F(x, 1, 0)))+1);
		}
	}
	else
	{
		dp[x][0] = min(dp[x][0], F(x, 0, 0));
		dp[x][1] = min(dp[x][1], min(F(x, 1, 1), min(F(x, 0, 1), F(x, 1, 0))));
		if (C[x])
		{
			dp[x][1] = min(dp[x][1], F(x, 1, 1)+1);
			dp[x][0] = min(dp[x][0], min(F(x, 0, 0), min(F(x, 0, 1), F(x, 1, 0)))+1);
		}
	}
	if (dp[x][0] > OO) dp[x][0] = OO;
	if (dp[x][1] > OO) dp[x][1] = OO;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &N);
	for (long a = 0; a < N; a ++)
	{
		long t;
		scanf("%d%d", &M, &V);
		for (long b = 1; b <= M; b ++)
			dp[b][0]=dp[b][1]=OO;
		for (long b = 1; b < (M+1)/2; b ++)
			scanf("%d%d", &O[b], &C[b]);
		for (long b = (M+1)/2; b <= M; b ++)
		{
			scanf("%d", &t);
			//printf("%d", t);
			dp[b][t]=0;
			dp[b][(long)(-1*t+1)]=OO;
			C[b]=0;
		}
		
		for (long b = (M+1)/2-1; b > 0; b --)
			Dp(b);

		if (dp[1][V]==OO)
			printf("Case #%d: IMPOSSIBLE\n", a+1);
		else
			printf("Case #%d: %d\n", a+1, dp[1][V]);
	}

	return 0;
}