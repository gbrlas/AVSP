#include<stdio.h>
#include<string.h>
#include<math.h>
long int gcd(long int a,long int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
main()
{
FILE *fin=fopen("a.in","r");
FILE *fout=fopen("a.out","w");
long int b,c,d,e,x,y,z;
double a,p,q,r,s,t;
fscanf(fin,"%ld",&b);
for(z=1;z<=b;z++)
{
    fprintf(fout,"Case #%ld: ",z);
    fscanf(fin,"%lf %ld %ld",&a,&c,&d);
    e=0;
    if((d==100 && c<100) || (d==0 && c>0))
    {
        e=1;
    }
    if((d==100 && c==0) || (d==0 && c==0))
    {
        goto l;
    }
    y=100;
    while(gcd(y,c)>1)
    {
        x=gcd(y,c);
        y/=x;
        c/=x;
    }
    if(y>(long int)a)
    {
        e=1;
    }
    l:if(e==0)
    {
        fprintf(fout,"Possible\n");
    }
    else
    {
        fprintf(fout,"Broken\n");
    }
}
return 0;
}
