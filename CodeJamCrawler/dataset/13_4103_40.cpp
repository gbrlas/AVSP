#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int check(int x)
{
    int a[10],k=0,i;
    while (x>0)
    {
        a[++k]=x%10;
        x=x/10;
    }
    for (i=1;i<=k/2;i++)
        if (a[i]!=a[k-i+1])
            return 0;
    return 1;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t,cas=0;
    scanf("%d",&t);
    while (t--)
    {
        int n,m,ans=0,i;
        scanf("%d%d",&n,&m);
        for (i=sqrt(n);i<=sqrt(m);i++)
        {
            if (i*i>=n&&i*i<=m)
            {
                if (check(i*i)==1&&check(i))
                {
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
