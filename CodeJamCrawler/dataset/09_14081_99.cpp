#include<stdio.h>
#include<string.h>
int a[40],l,m,ans,dp[600][22];
char s[600];
char*p="welcome to code jam";
int main()
{
		freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas=0,kk;
	scanf("%d",&kk);
	while (kk--)
	{
		memset(dp,0,sizeof(dp));
		do
		{
			gets(s);
			l=strlen(s);
		}while (!l);
		for (i=0;i<l;i++)
		{
			if (s[i]=='w')
			{
				dp[i][0]=1;
			}
		}
		for (j=1;j<19;j++)
		{
			for (i=0;i<l;i++)
			{
				if (s[i]==p[j])
				{
					for (k=0;k<i;k++)
					{
						dp[i][j]+=dp[k][j-1];
						dp[i][j]%=10000;
					}
				}
			}
		}
		int ans=0;
		for (i=0;i<l;i++)
		{
			ans+=dp[i][18];
			ans%=10000;
		}
		printf("Case #%d: %04d\n",++cas,ans);
	}
}
