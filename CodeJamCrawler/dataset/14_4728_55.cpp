#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        double c,f,x;
        scanf("%lf%lf%lf",&c,&f,&x);
        printf("Case #%d: ",cas);
        if (x<=c) printf("%.7f\n",x*0.5);
        else
        {
            double ans=0,v;
            v=2.0;
            while ((x-c)/v>x/(v+f))
            {
                ans+=c/v;
                v+=f;
            }
            ans+=x/v;
            printf("%.7f\n",ans);
        }
    }
    return 0;
}
