#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

int main()
{
    int t,i;
    double c,f,x,s1,s,k,s2;
    scanf("%d",&t);
    for(i=1;i<=t;++i)
    {
       scanf("%lf %lf %lf",&c,&f,&x);
       s = s1= 0.000000;
        k=2.0000000;
       printf("Case #%d: ",i);
       s = x/k;
       s1 = c/k;
       k+=f;
       s2 = s1+(x/k);
       //printf("%lf %lf\n",s ,s2);
       while(s2 < s)
       {
           s = s2;
           s1 +=(c/k);
           k+=f;
           s2 = s1+(x/k);
           //printf("%lf %lf\n",s ,s2);
       }
       printf("%.7lf\n",s);
    }
    return 0;
}
