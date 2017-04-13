#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
char s[15][15];
int res[15][1060],key[15],n,m,le[1060],ce[15];
int now[1060],next[1060],cntnum[1060];
bool legle(int a)
{
    int last=0;
    while(a)
    {
        if(a%2==1)
        {
            if(last==1)return 0;
            last=1;
        }
        else last=0;
        a/=2;
    }
    return 1;
}           
void dfs(int from,int num,int cnt)
{
    if(from==m)
    {
        if(le[num]==1)now[num]=cnt;
        return ;
    }    
    else
    {
        if(s[0][from]=='.')
        {
            dfs(from+1,num*2+1,cnt+1);
            dfs(from+1,num*2,cnt);
        }
        else 
        {    
            dfs(from+1,num*2,cnt);
        }
    }
    return ;
} 
bool ok(int num,int ceng)
{
    if(((num|ce[ceng])^ce[ceng])!=0)return 0;
    return 1;
}    
void now_to_next(int ceng)
{
    int i,j;
    for(i=0;i<key[m];i++)
    {
        next[i]=-1;
        if(ok(i,ceng))
        {
            for(j=0;j<key[m];j++)
            {
                if(now[j]!=-1&&le[j|i]==1)
                {
                    if(next[i]==-1)next[i]=cntnum[i]+now[j];
                    else next[i]=max(next[i],cntnum[i]+now[j]);
                }
            }
        }
    }
    for(i=0;i<key[m];i++)now[i]=next[i];
}            
int cal(int a)
{
    int res=0;
    while(a)
    {
        if(a%2==1)res++;
        a/=2;
    }
    return res;
}               
int main()
{
    freopen("in.txt","r",stdin);
    freopen("o.txt","w",stdout);
    int cas,ca=1,i,j,k,t;
    cin>>cas;
    key[1]=2;
    for(i=2;i<12;i++)key[i]=2*key[i-1];
    for(i=0;i<key[10];i++)
    {
        if(legle(i))le[i]=1;
        else le[i]=0;
    }    
    for(i=0;i<key[10];i++)
    {
        cntnum[i]=cal(i);
    }    
    while(cas--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            t=0;
            for(j=0;j<m;j++)
            {
                t*=2;
                if(s[i][j]=='.')t++;
            }    
            ce[i]=t;
        }    
        for(i=0;i<key[m];i++)now[i]=-1;
        dfs(0,0,0);
        for(i=1;i<n;i++)
        {
            now_to_next(i);
        }
        int res=0;
        for(i=0;i<key[m];i++)
        {
            if(now[i]>res)res=now[i];
        }
        printf("Case #%d: %d\n",ca++,res);
    }
    return 0;
}            
                
        
