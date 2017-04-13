#include<stdio.h>
int main()
{
    long long int q,w;
    double c,f,x,z,r,v,b;
    scanf("%lld",&q);
    for(w=1;w<=q;w++)
    {
        scanf("%lf %lf %lf",&c,&f,&x);
        r=2.0;
        z=x/r;
        b=c/r;
        v=b+(x/(f+r));
        while(v<z)
        {
            r=r+f;
            z=v;
            b=b+(c/r);
            v=b+(x/(f+r));
        }
        printf("Case #%lld: %.7lf\n",w,z);
    }
    return 0;
}
