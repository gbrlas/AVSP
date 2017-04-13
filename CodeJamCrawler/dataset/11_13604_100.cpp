#include <stdio.h>
#include <algorithm>

int val[105];
int pre[105];
int dp[105];
char ch[10];

inline int dabs(int x)
{
	return x > 0 ? x : -x;
}

int main ()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int ca;
	scanf("%d", &ca);
	int cas = 0;
	int n;
	while (ca--)
	{
		scanf("%d", &n);
		int x;
		int lasto = 0, lastb = 0;
		val[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s%d", ch, &val[i]);					
			if (ch[0] == 'O') 
			{
				pre[i] = lasto;
				lasto = i;
			}
			else
			{
				pre[i] = lastb;
				lastb = i;	
			}				
		}
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = std::max(dp[pre[i]] + dabs(val[i] - val[pre[i]]) + 1 , dp[i - 1] + 1);
		}
		printf("Case #%d: %d\n", ++cas, dp[n]);
	}
	return 0;
}
