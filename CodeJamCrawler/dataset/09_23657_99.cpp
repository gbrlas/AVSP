#include <stdio.h>
#include <string.h>

char sample[]=" welcome to code jam";

int main(){
	int ecase,ecount;
	char input[1000];
	int len;
	int i,j;
	int dp[30][1000];
	scanf("%d",&ecase);
	gets(input);
	for(ecount=1;ecount<=ecase;ecount++){
		gets(input+1);
		len=strlen(input+1);
		memset(dp,0,sizeof(dp));
		for(i=1;i<=len;i++){
			dp[1][i]=dp[1][i-1];
			if(input[i]=='w')
				dp[1][i]++;
		}
		for(i=2;sample[i];i++){
			for(j=1;j<=len;j++){
				dp[i][j]=dp[i][j-1];
				if(input[j]==sample[i]){
					dp[i][j]+=dp[i-1][j-1];
					dp[i][j]%=10000;
				}
			}
		}
		printf("Case #%d: %04d\n",ecount,dp[i-1][len]);
	}
	return 0;
}
