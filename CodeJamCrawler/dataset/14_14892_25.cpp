#include<stdio.h>

int main()
{
    int test,t;
    scanf("%d",&test);
    double c,f,x,t1=0,t2=0,q=0,s=2;
    int i;
    t=1;
    while(t<=test)
    {
        scanf("%lf",&c);
        scanf("%lf",&f);
        scanf("%lf",&x);
        t1=0,t2=0,q=0,s=2;
        while(1)
        {

            t1=t1+x/s;
            t2=q+c/s;
            q=t2;
            s=s+f;
            t2+=x/s;
            if(t2>t1)
            {
                break;
            }
            t1=q;
        }

    printf("Case #%d: %.7lf\n",t,t1);
    t++;
    }
    return 0;
}
