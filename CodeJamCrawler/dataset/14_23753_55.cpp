#include<cstdio>
#include<algorithm>
using namespace std;
double t[2005];
double tot[2005];
double pr[2005];
int main()
{
    double C,X,F;
    int T,it,i;
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("Cookie.out","w",stdout);
    scanf("%d",&T);
    for(it=1; it<=T; it++)
    {
        scanf("%lf%lf%lf",&C,&F,&X);
        t[0]=0.00;
        pr[0]=2.00;
        for(i=1; i<=2002; i++)
        {
            t[i]=t[i-1]+(C/pr[i-1]);
            pr[i]=pr[i-1]+F;
        }
        tot[0]=X/pr[0];
        for(i=1; i<=2002; i++)
           tot[i]=t[i]+(X/pr[i]);
        double Ans=tot[0];
        //printf("%.7lf\n",Ans);
        for(i=1; i<=2002; i++)  Ans=min(Ans,tot[i]);
        printf("Case #%d: %.7lf\n",it,Ans);
    }
    return 0;
}
