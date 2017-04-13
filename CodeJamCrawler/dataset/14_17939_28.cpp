#include<stdio.h>
int main()
{
double c,f,x,tt,ol,r;
int i,j,m=1,t;
scanf("%d",&t);
while(m<=t)
{ i=1;r=0.2;
scanf("%lf %lf %lf",&c,&f,&x);
ol=x/r;
f=f/10;
while(i)
{
r=0.2;tt=0.0;
for(j=1;j<=i;j++)
{
    tt+=c/r;
    r=r+f;
}
tt+=x/r;
if(ol<tt)
    break;
else ol=tt;
i++;
}
ol=ol*0.1;
printf("Case #%d: %.7lf\n",m,ol);
m++;
}
return(0);
}
