#include<cstdio>
using namespace std;
int main()
{
    double c,f,x;
    double rate = 2;
    double now = 0;
    int t;
    double tt;
    scanf("%d",&t);
    for (int i = 1; i <= t; i++){
        tt = 0;
        rate = 2.0;
        scanf("%lf%lf%lf",&c,&f,&x);
        while(x/rate >c/rate+x/(rate+f)){
            tt += c/rate;
            rate += f;
        }
        tt += x/rate;
        printf("Case #%d: %.7lf\n",i,tt);
    }

    return 0;
}
