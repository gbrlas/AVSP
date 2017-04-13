#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
   freopen ("C-small-attempt0.in","r",stdin);
   freopen ("out.txt","w",stdout);
   int t,i,j,a,b,n,r,c,s;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
   {
       c=0;
       scanf("%d %d",&a,&b);
       for (j=a;j<=b;j++)
       {
           n=j;
           r=0;
           while (n>0)
           {
               r=r*10+n%10;
               n=n/10;
           }
           if (j==r)
           {
               s=sqrt(j);
               if (s*s==j)
               {
                   n=s;
                   r=0;
                   while (n>0)
                   {
                      r=r*10+n%10;
                      n=n/10;
                    }
                    if (s==r)
                        c=c+1;
               }
           }
       }
       printf("Case #%d: %d\n",i,c);
   }
    return 0;
}
