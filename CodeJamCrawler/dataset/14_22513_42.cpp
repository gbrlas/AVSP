#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<list>
using namespace std;
int dp[105][105],all,oo,n,ans,q[10005];
char s[105],str[105][105];
inline int comp(int i,int j)
{
    return i<j;
}
int main()
{
    freopen("A-small-attempt0 (2).in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,ca=0,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int flag=1;
        for (int i=1; i<=n; i++)
        {
            scanf("%s",s);
            int p=strlen(s);
            all=1;
            k=0;
            for (int j=1; j<p; ++j)
                if (s[j]!=s[j-1])
                {
                    str[i][++k]=s[j-1];
                    dp[i][k]=all;
                    all=1;
                }
                else  all++;
            str[i][++k]=s[p-1];
            dp[i][k]=all;
            if (i!=1)
                for (int j=1; j<=k; ++j)
                    if (str[i][j]!=str[i-1][j])
                    {
                        flag=0;
                        break;
                    }
            if (!flag) break;
            if (i==1)
                oo=k;
            else if (k!=oo)
            {
                flag=0;
                break;
            }
        }
        if (!flag)
            printf("Case #%d: Fegla Won\n",++ca);
        else
        {
            printf("Case #%d: ",++ca,ans);
            ans=0;
            for (int i=1; i<=k; i++)
            {
                for (int j=1; j<=n; j++)
                    q[j]=dp[j][i];
                sort(q+1,q+n+1,comp);
                for (int j=1; j<=n/2; j++)
                    ans+=q[n-j+1]-q[j];
            }
            printf("%d\n",ans);
        }
    }
}
