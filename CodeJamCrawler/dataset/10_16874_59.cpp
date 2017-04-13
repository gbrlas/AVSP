#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;
const int inf = 1000000;

int dp[1010][1010];
int a[1010];
int min_num(int x,int y)
{
	if(x<=y)
		return x;
	return y;
}
int max_num(int x,int y)
{
	if(x>=y)
		return x;
	return y;
}
int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("temp.txt","w",stdout);
	
	int t,cas=1;
	int i,j,k,de,ins,m;
	int n,c,nn;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&de,&ins,&m,&n);
		nn=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			nn=max_num(a[i],nn);
		}
		for(i=0;i<n;i++)
			for(j=0;j<=nn;j++)
				dp[i][j]=inf;
		dp[0][a[0]]=0;
		for(i=0;i<=nn;i++)
		{
			if(min_num(abs(i-a[0]),de)<dp[0][i])
				dp[0][i]=min_num(abs(i-a[0]),de);
		}
		
		for(i=0;i<n-1;i++)
			for(j=0;j<=nn;j++)
				if(dp[i][j]<inf)
				{
					dp[i+1][j]=min_num(dp[i][j]+de,dp[i+1][j]);;
					int p;
					for(k=0;k<=nn;k++)
					{
						int num = abs(k-a[i+1]);
						p = abs(k-j);
						
						
						if(p<=m) p=0;
						else
						{
							if(m==0)
							{
								p=inf;
								continue;
							}
							else{
								if(p%m==0)
									p=p/m-1;
								else p=p/m;
							}
						}
						if(dp[i][j]+p*ins+num<dp[i+1][k])
							dp[i+1][k]=dp[i][j]+p*ins+num;
					
					}	
				}
	
		int ans = inf;
		if(de==0) ans =0;
		for(i=0;i<=nn;i++)
			if(ans>dp[n-1][i])
				ans = dp[n-1][i];
		printf("Case #%d: ",cas++);
		printf("%d\n",ans);
		
	}
}
