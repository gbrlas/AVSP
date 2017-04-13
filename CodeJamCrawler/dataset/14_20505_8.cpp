#include <stdio.h>
#include <conio.h>

int main()
 {
     int i=0,T,l,m,k,a,b,ans,check=0;
    freopen("input.in","r",stdin);
    freopen("out.out","w",stdout);

    scanf("%d",&T);
    for( i=0;i<T;i++)
    {
      l=check=0;
      scanf ("%d %d %d",&a,&b,&k);
      while(l<a)
      {
          m=0;
          while(m<b)
          {
              ans=l&m;
              if(ans<k)
                check++;
              m++;
          }
          l++;
      }
      printf("Case #%d: %d\n",i+1,check);
    }
    return 0;
 }
