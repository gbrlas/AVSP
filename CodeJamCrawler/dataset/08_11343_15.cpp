#include <iostream>
#include <algorithm>
using namespace std;

char map[20][20];
int dp[20][1<<11], N, M;

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int t; scanf("%d", &t);
	for (int step=1; step<=t; step++)
	{
		scanf("%d%d", &N, &M);
		for (int i=0; i<N; i++) scanf("%s", map[i]);
		memset(dp, 0, sizeof(dp));
		for (int i=0; i<N; i++)
			for (int j=0; j<(1<<M); j++)
			{
				int s=0;
				for (int k=0; k<M; k++) if (map[i][k]=='.') s|=(1<<k);
				s=s&j;
				for (int k=0; k<=s; k++) if ((k&s)==k)
				{
					bool t=true;
					for (int l=1; l<M; l++) if (((1<<l)&k)!=0 && (((1<<(l-1))&k)!=0))
					{
						t=false;
						break;
					}
					if (!t) continue;
					int sum=0, ans=dp[i][j];
					for (int l=0; l<M; l++) if (((1<<l)&k)!=0)
					{
						if (l>0) sum|=(1<<(l-1));
						if (l<M-1) sum|=(1<<(l+1));
						ans++;
					}
					dp[i+1][(1<<M)-1-sum]=max(dp[i+1][(1<<M)-1-sum], ans);
				}
			}
		int ans=0;
		for (int i=0; i<(1<<M); i++) ans=max(ans, dp[N][i]);
		printf("Case #%d: %d\n", step, ans);
	}
	return 0;
}
