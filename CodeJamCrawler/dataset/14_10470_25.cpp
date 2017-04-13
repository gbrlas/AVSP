#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main()
{
    int cas;
    scanf("%d",&cas);
    int sn=0;
    while(cas--)
    {
        double c,x,f;
        double ans=0;
        scanf("%lf%lf%lf",&c,&f,&x);
        ans=x/2;
        double as=0;
        for(int i=1;;i++)
        {
            double r=f*i+2;
            as+=c/(r-f);
            if(as>ans)
             break;
            ans=min(ans,as+x/r);
        }
        printf("Case #%d: %.7f\n",++sn,ans);
    }
    return 0;
}
