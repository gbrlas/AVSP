#include<stdio.h>
int main()
{
    double c,f,x,t1=2,p1,p2,p3=0;
    int t,pp;
    scanf("%d",&t);
    pp=t;
    while(t--)
    {	p3=0;
    	t1=2;
        scanf("%lf %lf %lf",&c,&f,&x);
        p1=x/t1;
        p2=(c/t1);
        p2=p2+(x /(f+t1));
        if(p1>p2)
        {
            p2=p2-(x /(f+t1));
            p3=p2;
            t1+=f;
        while(1)
        {
            p1=x/t1;
            p2 = (c / t1) + (x /(f+t1));

            if(p1 > p2)
            {
                p3+=c/t1;
                t1+=f;
            }
            else
            {
                p3+=x/t1;
                break;
            }
        }
        }
        else
            {
             p3+=x/t1;

        }
        printf("Case #%d: %.7lf\n",pp-t,p3);

    }
return 0;
}
