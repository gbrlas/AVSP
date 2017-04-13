#include <cstdio>
#include <algorithm>

using namespace std;

#define eps 1e-9
double curans = 0;

int main()
{
    int t;
    scanf("%d",&t);
    int cas;
    for(cas=1;cas<=t;cas++)
    {
        double C,F,X;
        scanf("%lf%lf%lf",&C,&F,&X);
        
        double ans = X/2;
        double curF=2;
        double curans=0;
        int i;
        for(i=0;i<=X;i++)
        {
            curans+=(C/curF);
            curF+=F;
            ans=min(ans,curans+X/curF);
        }

        printf("Case #%d: %0.7lf\n",cas,ans); 
    }
}
