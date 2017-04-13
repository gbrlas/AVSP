#include<stdio.h>
int main()
{
    int t;
    int cases=0;
    scanf("%d",&t);
    while(t--)
        {
            cases++;
            double c,f,x;
            scanf("%lf %lf %lf",&c,&f,&x);
            double speed = 2.0;
            double time = 0;
            while(1)
                {
                    //printf("c=%g f=%g x=%g speed=%g\n",c,f,x,speed);
                    //break;
                    double a = x/speed;
                    double b = c/speed + x/(speed+f);
                    if(a<=b)
                        {
                            time = time + a;
                            break;
                        }
                    else
                        {
                            time = time + c/speed;
                            speed = speed + f;
                        }

                }
            printf("Case #%d: %.7f\n",cases,time);
        }
    return 0;
}
