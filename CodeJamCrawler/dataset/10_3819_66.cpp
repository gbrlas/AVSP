#include <stdio.h>
#include <math.h>
int main()
{
    int p,i,n,k,T;

        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d%d",&n,&k);
        p = (int)pow(2.0,(double)n);
        if(k==p-1 || (k-p+1)%p==0)
        {
            printf("Case #%d: ON\n",i);
        }
        else printf("Case #%d: OFF\n",i);
    }
    return 0;
}