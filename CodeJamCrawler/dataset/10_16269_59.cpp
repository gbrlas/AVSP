#include <iostream>
#include <cstdio>
using namespace std;
#define INF 0X7FFFFFFF
int n,m,D,I;
int dp[105][300];
int x[105];
void init()
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=0;j<=255;j++)
            dp[i][j]=INF;
    for(i=0;i<=255;i++) dp[0][i]=0;
//    dp[1][x[1]]=0;
}
void debug()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=255;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t,T;
    int i,j,k;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>D>>I>>m>>n;
        for(i=1;i<=n;i++) scanf("%d",x+i);
        init();
        for(i=0;i<n;i++)
        {
            int mincost=INF;bool flag=0;
            while(1)
            {
                flag=0;
                for(j=0;j<=255;j++)
                {
                    if(dp[i][j]!=INF)
                    {
                        int low=j-m>=0?j-m:0;
                        int high=j+m<=255?j+m:255;
                        for(k=low;k<=high;k++)
                        {
                            if(dp[i][k]>dp[i][j]+I) flag=1;
                            dp[i][k]=min(dp[i][k],dp[i][j]+I);
                        }
                    }
                }
                if(!flag) break;
            }
//            for(j=0;j<=255;j++)
//                dp[i][j]=min(dp[i][j],mincost+I);//insert
            for(j=0;j<=255;j++)
            {
                int low=j-m>=0?j-m:0;
                int high=j+m<=255?j+m:255;
                for(k=low;k<=high;k++)
                {
                    dp[i+1][k]=min(dp[i+1][k],dp[i][j]+abs(k-x[i+1]));//change
//                    if(i+1==1&&j==0) cout<<i<<" "<<j<<" "<<k<<" "<<x[i+1]<<endl;
                }
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+D);//delete
            }

        }
//        debug();
        int ans=INF;
        for(i=0;i<=255;i++) ans=min(dp[n][i],ans);
        printf("Case #%d: %d\n",t,ans);

    }
    return 0;
}
