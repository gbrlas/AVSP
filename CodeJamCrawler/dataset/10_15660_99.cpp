#include<iostream>
using namespace std;
int main()
{
   // freopen("A-small-attempt0.in","r",stdin);
   // freopen("A-small-attempt0.out","w",stdout);
    int t,k,n,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&k);
        if((k+1)%(1<<n)==0) printf("Case #%d: ON\n",i);
        else printf("Case #%d: OFF\n",i);
    }
}
