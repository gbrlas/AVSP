#include<stdio.h>

int main()
{
int T,iter=1;

scanf("%d",&T);
while (iter <= T)
{   double speed=2;
    double C,F,X,time=0,f1,f2;
    int flag=0;
    scanf("%lf",&C);
    scanf("%lf",&F);
    scanf("%lf",&X);
    //C-farm cost, F-rate increase by , X-total cookies
    while (flag == 0)
    {   f1 = time + C/speed + X/(speed+F);
        f2 = time+X/speed;
        //printf("%f %f",f1,f2);
        if (f1 < f2)
        {

            time = time + C / (speed);
            speed += F;

        }

        else
            flag = 1;


    }
    time = time + X/speed;
    printf("Case #%d: %.7lf\n",iter,time);

    iter++;
}



return 0;
}
