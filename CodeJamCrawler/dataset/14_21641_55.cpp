#include <stdio.h>
#include <stdlib.h>

int main()
{ freopen("B-small-attempt2.in","r",stdin);
    freopen("B out.txt","w",stdout);
int n,i,j;
double x,f,c,p,z,f1,f2,t;
scanf("%d",&n);
for(i=0;i<n;i++)
  {scanf("%lf %lf %lf",&c,&f,&x);
    p=2.0;
    z=0.0;
   for(j=0;j<2000;j++)
        {
            f1=p+j*f;
            f2=p+(j+1)*f;
            if((x/f1)>(c/f1+x/f2))
            {
                t=c/f1;
                z+=t;
            }
            else
            {
                z+=x/f1;
                break;

            }
        }
  printf("Case #%d: %.7lf\n",i+1,z);
  }

return 0;
}
