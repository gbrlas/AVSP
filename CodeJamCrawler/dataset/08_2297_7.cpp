#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<int> vec1[20],vec2[20];
int mark[10],n,m,cnt1[10],cnt2[10],flag,to[10],vis[10];
void f(int from)
{
    if(flag)return ;
    int i,j,tag,k,t;
    if(from==n+1)
    {
        for(i=1;i<=m;i++)
        {
            for(j=0;j<vec2[i].size();j++)
            {
                k=vec2[i][j];
                tag=0;
                for(t=0;t<vec1[to[i]].size();t++)
                {
                    if(to[k]==vec1[to[i]][t])tag=1;
                }
                if(tag==0)return ;
            }
        }
        flag=1;
        return ;
    }
    if(mark[from]==0)f(from+1);
    for(j=1;j<=m;j++)
    {
        if(vis[j]==0)
        {
            vis[j]=1;
            to[j]=from;
            f(from+1);
            vis[j]=0;
        }
    }
    return ;
}
void check()
{
    memset(vis,0,sizeof(vis));
    f(1);
}
void dfs(int from,int cnt)
{
    if(flag)return ;
    if(cnt>m)return ;
    if(from==n+1)
    {
        if(cnt==m)check();
        return ;
    }
    mark[from]=1;
    dfs(from+1,cnt+1);
    mark[from]=0;
    dfs(from+1,cnt);
    return ;
}
    
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas,ca=1,i,j,k,p,q;
    cin>>cas;
    while(cas--)
    {
        cin>>n;
        for(i=1;i<=n;i++)vec1[i].clear();
        for(i=1;i<n;i++)
        {
            cin>>p>>q;
            vec1[p].push_back(q);
            vec1[q].push_back(p);
        }
        cin>>m;
        for(i=1;i<=m;i++)vec2[i].clear();
        for(i=1;i<m;i++)
        {
            cin>>p>>q;
            vec2[p].push_back(q);
            vec2[q].push_back(p);
        }
        flag=0;
        memset(mark,0,sizeof(mark));
        dfs(1,0);
        printf("Case #%d: ",ca++);
        if(flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
            
