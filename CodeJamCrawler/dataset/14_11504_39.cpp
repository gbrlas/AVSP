#include<stdio.h>
int main()
{
int t,k=1;
scanf("%d",&t);
for(k=1;k<=t;k++)
{
int i=0;
double c,f,x,j=0,ii=0,cc=0;
scanf("%lf %lf %lf",&c,&f,&x);

ii=x/2;

while(1)
{


     j+=c/(2+i*f) ;

     cc=j+x/(2+((i+1)*f)) ;

     if(cc>ii)
     break;

     else
     ii=cc;

      i++;

}


printf("Case #%d: %.7lf\n",k,ii);
}

return 0;
}
