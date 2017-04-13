#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<map>
#include<vector>

using namespace std;

int d[2010];
int price[11][2010];
int dp[11][2010][11];
int n,sum;
const int inf = 100000000;

int min_num(int n1,int n2)
{
	if(n1<=n2)
		return n1;
	return n2;
}
int dfs(int p,int num)
{	
	int i;
	if(p==n)
	{
		for(i=0;i<=d[num];i++)
		dp[p][num][i]=0;
		return d[num];
	}
	int n1 = dfs(p+1,2*num);
	int n2 = dfs(p+1,2*num+1);
	int nn = min_num(n1,n2);

	for(i=0;i<=nn;i++)
		dp[p][num][i]=dp[p+1][2*num][i]+dp[p+1][2*num+1][i]+price[p][num];
	for(i=0;i<nn;i++)
		dp[p][num][i] = min_num(dp[p][num][i],
			dp[p+1][2*num][i+1]+dp[p+1][2*num+1][i+1]);
	
	return nn;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("temp.txt","w",stdout);
	
	int t,cas=1;
	int i,j,k,num;
	
	scanf("%d",&t);
	while(t--)
	{		
		scanf("%d",&n);
		sum=0;
		for(i=0;i<(1<<n);i++)
			scanf("%d",&d[i]);
		for(i=n-1;i>=0;i--)
			for(j=0;j<(1<<i);j++)
				scanf("%d",&price[i][j]);
		
		for(i=0;i<=n;i++)
			for(j=0;j<(1<<i);j++)
				for(k=0;k<=n;k++)
					dp[i][j][k]=inf;
		dfs(0,0);
		printf("Case #%d: ",cas++);
		printf("%d\n",dp[0][0][0]);
	}
}
