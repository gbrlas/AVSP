#include<stdio.h>
int main()
{
    int t,i,n,k;
    freopen("a.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&t);
    for(i=0;i<t;i++)
     {
        scanf("%d%d",&n,&k);
        if((k+1)%(1<<n)==0) printf("Case #%d: ON\n",i+1);
    else printf("Case #%d: OFF\n",i+1);
     }
     return 0;
}

