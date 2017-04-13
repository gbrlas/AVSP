#include<cstdio>
using namespace std;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("22.out","w",stdout);
    int T;
    double c,f,x,s;
    double min1;
    scanf("%d",&T);
    for(int n=1; n<=T; n++)
    {
        min1=0.0;
        s=2.0;
        scanf("%lf %lf %lf",&c,&f,&x);

        if((x/s)>(x/(s+f)+c/s))
            {
                while((x/s)>(x/(s+f)+c/s))
                {
                    min1 = min1 + c/s;
                    //printf("mai ge nongchang!\n");
                   // printf("%lf\n",c/s);
                    s = s + f;
                    //printf("c=%lf,f=%lf,x=%lf,s=%lf\n",c,f,x,s);

                }
                min1 = min1 + (x/s);
            }
            else
            {
                min1 = min1 + (x/s);
            }
            printf("Case #%d: ",n);
            printf("%.7lf\n",min1);
    }
    return 0;
}
