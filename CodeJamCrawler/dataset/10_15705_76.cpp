#include<iostream>
using namespace std;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t,l,p,c,x,y,s,i;
    double sum;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&l,&p,&c);
        sum=p*1.0/l;
        x=1;s=c;
        while(s<sum)  {s*=c;x++;}

        y=0;s=1;
        while(s<x)
        {
            y++;s*=2;
        }
        printf("Case #%d: %d\n",i,y);
    }
    return 0;
}
