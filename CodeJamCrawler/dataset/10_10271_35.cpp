#include <iostream>
#include <stdio.h>
#include <memory.h>
#define N 256
using namespace std;
int dp[N][N];
int a[N];
int D,I,M,n;
int ABS(int n)
{
	return n>0?n:-n;
}
void Del(int i)
{
	int j;
	for(j=0;j<N;j++)
	{
		if(dp[i-1][j]!=-1)
			dp[i][j]=dp[i-1][j]+D;	
	}	
}
void Insert(int i)
{
	int j,k;
	for(j=0;j<N;j++)
	{
		if(dp[i-1][j]!=-1)
		{
			int sub=ABS(a[i]-j);
			sub--;
			if(sub<0) sub=0;
			int t;
			if(M!=0)
				t=sub/M*I;
			else
			{
				return ;
			}
			if(dp[i][a[i]]==-1)
				dp[i][a[i]]=t+dp[i-1][j];
			else if(dp[i][a[i]]>dp[i-1][j]+t)
				dp[i][a[i]]=dp[i-1][j]+t;
		}	
	}	
}
void Change(int i)
{
	int j,k;
	for(j=0;j<N;j++)
	{
		if(dp[i-1][j]!=-1)
		{
			int start=j-M>0?j-M:0;
			int end=j+M<N?j+M:N-1;
			for(k=start;k<=end;k++)	
			{
				int t=ABS(k-a[i]);
				if(dp[i][k]==-1)
					dp[i][k]=dp[i-1][j]+t;
				else dp[i][k]=dp[i][k]>dp[i-1][j]+t?dp[i-1][j]+t:dp[i][k];
			}
		}	
	}	
}
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	freopen("B-small-attempt4.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	scanf("%d",&T);
	int cas=1;
	while(T--)
	{
		scanf("%d%d%d%d",&D,&I,&M,&n);
		int i;
		memset(dp,-1,sizeof(dp));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		dp[0][a[0]]=0;
		for(i=0;i<N;i++)
		{
			if(i==a[0])
				continue;
			dp[0][i]=min(D,ABS(a[0]-i));
		}
		int j,k;
		for(i=1;i<n;i++)
		{
			Del(i);	
			Insert(i);
			Change(i);
		}	
		int MIN=0x7fffff;
		for(i=0;i<N;i++)
		{
			if(dp[n-1][i]==-1)
				continue;
			if(dp[n-1][i]<MIN)
				MIN=dp[n-1][i];
		}
		printf("Case #%d: %d\n",cas++,MIN);	
	}	
	return 0;
}
