#include<cstdio>
#include<algorithm>
using namespace std;
double t[100005];
double pr[100005];
int main()
{
    double C,X,F;
    int T,it,i;
    //freopen("B-large.in","r",stdin);
    //freopen("Cookie2.out","w",stdout);
    scanf("%d",&T);
    for(it=1; it<=T; it++)
    {
        scanf("%lf%lf%lf",&C,&F,&X);
        t[0]=0.00;
        pr[0]=2.00;
        for(i=1; i<=100002; i++)
        {
            t[i]=t[i-1]+(C/pr[i-1]);
            pr[i]=pr[i-1]+F;
        }
        for(i=0; i<=100002; i++)
           t[i]+=(X/pr[i]);
        double Ans=t[0];
        //printf("%.7lf\n",Ans);
        for(i=1; i<=100002; i++)  Ans=min(Ans,t[i]);
        printf("Case #%d: %.7lf\n",it,Ans);
    }
    return 0;
}
