#include<stdio.h>
#define min(a,b) a<=b?a:b
double c,x,f;
double mintime(double rate)
{
    if(x/rate<=c/rate+x/(rate+f))
    return x/rate;
    //printf("...%lf...\n",rate);
    return c/rate+mintime(rate+f);
}

int main()
{
    int t,i;
    double ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf%lf%lf",&c,&f,&x);
        ans=mintime(2.0);
        printf("Case #%d: %.7lf\n",i,ans);
    }
    return 0;
}
    
        
