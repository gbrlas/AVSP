#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int a[110][110];
int b[110][110];
bool isok(int n , int m)
{
    bool ok = true;
    int h[110] = {0};
    int l[110] = {0};
    int i,j;
    for(i=1 ; i <= n; i++)
    {
        for(j=1 ;j <= m; j++)
        {
            h[i] = max(h[i],a[i][j]);
        }
    }
    for(i=1 ; i <= m; i++)
    {
        for(j=1 ;j <= n; j++)
        {
            l[i] = max(l[i],a[j][i]);
        }
    }
    for(i = 1; i <= n ; i++)
    {
        for(j = 1; j<= m; j++)
        {
            if(a[i][j]<h[i]&&a[i][j]<l[j])
            {ok = false;break;}
        }
        if(ok==false)
            break;
    }
    return ok;
}
int main()
{
    freopen("d:\\B-large.in","r",stdin);
    freopen("d:\\b11111out.txt","w",stdout);
    int i,j,n,m;
    int t,ncase;
    scanf("%d",&ncase);
    for(t = 1 ; t <= ncase; t++)
    {
        scanf("%d%d",&n,&m);
        for(i = 1; i<=n ;i++)
            for(j = 1 ; j <= m ;j++)
               scanf("%d",&a[i][j]);
        if(isok(n,m))
            printf("Case #%d: YES\n",t);
        else
            printf("Case #%d: NO\n",t);
    }
}
