#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[510];
int dp[20][510],dp2[20][510];
int test,z;
char mt[20] = "welcome to code jam";
char junk;
main()
{
    int i,j,k,len,sum;
    scanf("%d",&test);
    scanf("%c",&junk);
    for(z=0;z<test;z++)
    {
        for(i=0;i<20;i++)for(j=0;j<510;j++)dp[i][j]=dp2[i][j]=0;
        gets(s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(mt[18]==s[i])dp[18][i]=1;

        }
        for(i=len-1;i>=0;i--)
        {
            dp2[18][i]=dp2[18][i+1]+dp[18][i];
            dp2[18][i]%=10000;
        }

        for(j=17;j>=0;j--)
        {
            for(i=0;i<len;i++)
            {
                if(mt[j]==s[i])
                {
                    dp[j][i]=dp2[j+1][i+1];
                }
            }
            for(i=len-1;i>=0;i--)
            {
            dp2[j][i]=dp2[j][i+1]+dp[j][i];
            dp2[j][i]%=10000;
            }
        }
        printf("Case #%d: ",z+1);
        if(dp2[0][0]<10)printf("000%d\n",dp2[0][0]);
        else if(dp2[0][0]<100)printf("00%d\n",dp2[0][0]);
        else if(dp2[0][0]<1000)printf("0%d\n",dp2[0][0]);
        else printf("%d\n",dp2[0][0]);
    }
}
