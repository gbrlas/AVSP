# include <stdio.h>
# include <string.h>

int S,Q;
char sch[105][105];
char que[1005][105];

int dp[1005][105];
void min(int &a,int b)
{
	if(a>b)a=b;
}
int solve()
{
	int i,j,k;
	memset(dp,0,sizeof(dp));
	for(j=0;j<S;j++)
		if(strcmp(sch[j],que[0])==0)
			dp[0][j]=-1;
	int min1;
	for(i=1;i<Q;i++)
	{
		for(j=0;j<S;j++)
		{
			min1=100000000;
			if(strcmp(sch[j],que[i])!=0)
			{
				for(k=0;k<S;k++)
					if(dp[i-1][k]!=-1)
					{
						if(k!=j)
							min(min1,dp[i-1][k]+1);
						else
							min(min1,dp[i-1][k]);
					}
				dp[i][j]=min1;
			}
			else
				dp[i][j]=-1;	
		}
	}
	min1=100000000;
	for(j=0;j<S;j++)
		if(dp[Q-1][j]!=-1)
			min(min1,dp[Q-1][j]);
	return min1;
}

int main()
{
	int n,t,i;
	scanf("%d",&n);
	for(t=1;t<=n;t++)
	{
		scanf("%d",&S);
		getchar();
		for(i=0;i<S;i++)
			gets(sch[i]);
		scanf("%d",&Q);
		getchar();
		for(i=0;i<Q;i++)
			gets(que[i]);
		printf("Case #%d: %d\n",t,solve());
	}
	return 0;
}
