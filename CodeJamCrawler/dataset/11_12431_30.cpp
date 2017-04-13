#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;


const int MaxN=1111;
int Testnum,N,tmp,ans,cnt,cur1,cur2,tot;
int a[MaxN];

void dfs(int dep)
{
    if (dep==N+1)
    {
        if ((cur1==cur2)&&(cnt<tot)) ans=max(ans,cnt);
        return;
    } 
    cur1^=a[dep];
    dfs(dep+1);
    cur1^=a[dep];
    cur2^=a[dep];
    cnt+=a[dep];
    dfs(dep+1);
    cnt-=a[dep];
    cur2^=a[dep];
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    
    cin>>Testnum;
    for (int Test=1; Test<=Testnum; ++Test)
    {
        printf("Case #%d: ",Test);  
        scanf("%d",&N);
        tmp=0;
        tot=0;
        for (int i=1; i<=N; ++i)
        {
            scanf("%d",&a[i]);
            tmp=tmp^a[i];
            tot+=a[i];
        }
        if (tmp) 
        {
            printf("NO\n");
            continue;
        }
        ans=0;
        cur1=0;
        cur2=0;
        cnt=0;
        dfs(1);
        printf("%d\n",ans);
    }
    
    return 0;
}
