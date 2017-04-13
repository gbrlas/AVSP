#include <stdio.h>
#include <stdlib.h>
int main()
{    freopen("A-small-attempt2.in","r",stdin);
    freopen("A out.txt","w",stdout);
    int a[16],b[16],i,j,n,m,x,y,c,p;
int flag;
scanf("%d",&n);
for(i=0;i<n;i++)
 {flag=0;
   scanf("%d",&x);
   for(j=0;j<16;j++)
    scanf("%d",&a[j]);
  scanf("%d",&y);
   for(j=0;j<16;j++)
    scanf("%d",&b[j]);
  for(p=4*(x-1);p<=(4*x-1);p++)
  {
    for(m=4*(y-1);m<=(4*y-1);m++)
 {

   if(a[p]==b[m])
    {
      flag++;
      c=a[p];
    }
 }

}
if(flag==0)
  printf("Case #%d: Volunteer cheated!\n",i+1);
if(flag==1)
printf("Case #%d: %d\n",i+1,c);
if(flag>1)
  printf("Case #%d: Bad magician!\n",i+1);


}


return 0;
}
