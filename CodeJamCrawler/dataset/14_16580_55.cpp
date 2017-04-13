#include<stdio.h>
int main()
{
   int t,i;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
     double  c,f,x,p,t=0,k=2;
     scanf("%lf %lf %lf",&c,&f,&x);
     p=x;
    if(p>c)
    {
    while(x>c)
    {
     if(p/k - p/(k+f) > c/k)
     {
       t+=c/k;
       k+=f;
       x=x-c;
     }
     else
     goto l;
    }
   l: t=t+p/k;
    printf("Case #%d: %0.7lf\n",i+1,t);
   }
   else
   {
     t=p/k;
     printf("Case #%d: %0.7lf\n",i+1,t);
   }
  }
   return 0;
}
