#include<stdio.h>
int main()
{
    double c,f,x,r,a,time;
    int tc,sr=1;
    FILE *fr=fopen("input3.in","r");
    FILE *fw=fopen("output4","w");

    fscanf(fr,"%d",&tc);

    while(tc--)

    {
        fscanf(fr,"%lf%lf%lf",&c,&f,&x);
        a=(x-c);time=0;  r=2;
        while(1)
        {

            if(a/r>x/(r+f))
            {
               time+=(c/r);
               r=r+f;
            }
            else
            {
                time+=x/r;
                break;

            }
        }
        fprintf(fw,"Case #%d: %.7lf\n",sr++,time);
    }
    return 0;
}
