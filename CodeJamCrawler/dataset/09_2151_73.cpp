#include<stdio.h>
#include<stdlib.h>

int dp[110][110];
int pris[110];
int p,q,t;

int dpx(int f,int t)
{
    int i,j,mn=99999999,c;
    if(dp[f][t]!=-1)return dp[f][t];

    if(f==t)
    {
        c=pris[f]-pris[f-1]-1+pris[t+1]-pris[t]-1;
        return dp[f][t]=c;
    }

    c=dpx(f+1,t)+pris[f]-pris[f-1]-1+pris[t+1]-pris[f]-1;
    if(c<mn)mn=c;

    c=dpx(f,t-1)+pris[t+1]-pris[t]-1+pris[t]-pris[f-1]-1;
    if(c<mn)mn=c;

    for(i=f+1;i<t;i++)
    {
        c=dpx(f,i-1)+dpx(i+1,t)+pris[t+1]-pris[i]-1+pris[i]-pris[f-1]-1;
        if(c<mn)mn=c;
    }

    return dp[f][t]=mn;
}

main()
{
    int i,j,k,z;
    scanf("%d",&t);
    for(z=0;z<t;z++)
    {
        scanf("%d%d",&p,&q);
        pris[0]=0;
        for(i=1;i<=q;i++)scanf("%d",&pris[i]);
        pris[q+1]=p+1;
        for(i=0;i<110;i++)for(j=0;j<110;j++)dp[i][j]=-1;
        printf("Case #%d: %d\n",z+1,dpx(1,q));
    }
}
