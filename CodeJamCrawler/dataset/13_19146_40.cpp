#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main()
{
   int a[]={1,4,9,121,484};
   int i,j,t,x,y,c;
   scanf("%d",&t);
   for(i=1;i<=t;++i)
   {
      scanf("%d %d",&x,&y);
      c=0;
      for(j=0;j<5;++j)
      {
         if(a[j]>=x && a[j]<=y) ++c;
      }
      printf("Case #%d: %d\n",i,c);
   }
   return 0;
}
