#include <iostream>
using namespace std;
int a[10010][3],res[10010][2];
int calcal(int a,int b)
{
    if(a==-1||b==-1)return -1;
    return a+b;
}
int minmin(int a,int b)
{
    if(a==-1)return b;
    if(b==-1)return a;
    if(a>b)return b;
    return a;
}
int minmin2(int a,int b)
{
    if(a==-1)
    {
        if(b==-1)return -1;
        return b+1;
    }
    if(b==-1)return a;
    if(b+1<a)return b+1;
    return a;
}
void cal(int i)
{
    int l=i*2,r=i*2+1;
    res[i][0]=-1;
    res[i][1]=-1;
    if(a[i][0]==1)
    {
        res[i][1]=minmin(res[i][1],calcal(res[l][1],res[r][1]));
        res[i][0]=minmin(res[i][0],calcal(res[l][1],res[r][0]));
        res[i][0]=minmin(res[i][0],calcal(res[l][0],res[r][0]));
        res[i][0]=minmin(res[i][0],calcal(res[l][0],res[r][1]));
        if(a[i][1]==1)
        {
            res[i][0]=minmin2(res[i][0],calcal(res[l][0],res[r][0]));
            res[i][1]=minmin2(res[i][1],calcal(res[l][1],res[r][0]));
            res[i][1]=minmin2(res[i][1],calcal(res[l][1],res[r][1]));
            res[i][1]=minmin2(res[i][1],calcal(res[l][0],res[r][1]));
        }          
    }
    else 
    {
        res[i][0]=minmin(res[i][0],calcal(res[l][0],res[r][0]));
        res[i][1]=minmin(res[i][1],calcal(res[l][1],res[r][0]));
        res[i][1]=minmin(res[i][1],calcal(res[l][1],res[r][1]));
        res[i][1]=minmin(res[i][1],calcal(res[l][0],res[r][1]));
        if(a[i][1]==1)
        {
            res[i][1]=minmin2(res[i][1],calcal(res[l][1],res[r][1]));
            res[i][0]=minmin2(res[i][0],calcal(res[l][1],res[r][0]));
            res[i][0]=minmin2(res[i][0],calcal(res[l][0],res[r][0]));
            res[i][0]=minmin2(res[i][0],calcal(res[l][0],res[r][1]));
        }
            
    }
    return ;
}
int main()
{
    int cas,i,j,t,k,n,ca=1;
    freopen("in.txt","r",stdin);
    freopen("o.txt","w",stdout);
    cin>>cas;
    while(cas--)
    {
        cin>>n>>t;
        for(i=1;i<=(n-1)/2;i++)
        {
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
        for(i=(n-1)/2+1;i<=n;i++)
        {
            scanf("%d",&k);
            res[i][k]=0;
            res[i][(k+1)%2]=-1;
        }
        for(i=(n-1)/2;i>=1;i--)
        {
            cal(i);
        }
        printf("Case #%d: ",ca++);
        if(res[1][t]==-1)printf("IMPOSSIBLE\n");
        else printf("%d\n",res[1][t]);
    }
    return 0;
}
            
