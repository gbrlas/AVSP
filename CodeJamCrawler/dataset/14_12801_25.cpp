#include <stdio.h>
void main()
{
int i,j,k,t,T;
double ta,F,C,X;
int n,N;
scanf("%d", &T);
for(t=1;t<=T;t++)
{
ta=0.0;
scanf("%lf %lf %lf", &C, &F, &X); 
for(i=0;i<1000000;i++)
if(((C/(2+i*F))+(X/(2+(i+1)*F)))>(X/(2+i*F)))
{ N=i; break; }
for(i=0;i<N;i++)
ta+=C/(2+i*F);
ta+=X/(2+i*F);
printf("Case #%d: %.7lf\n",t,ta);
}
}
