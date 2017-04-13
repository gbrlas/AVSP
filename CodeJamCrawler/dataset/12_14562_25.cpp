#include<stdio.h>
#include<math.h>
int k,a,b,x;
int compute(int n1,int x1)
{
do
{
n1=(n1%10)*pow(10,x1)+n1/10;
//printf("%d\n",n1);
if(n1>=a&&n1<=b&&n1>x)
{
k++;
//printf("(%d,%d)\n",x,n1);
}
}while(n1!=x);
return k;
}
int main()
{
int t,y,i,j,n;
scanf("%d",&t);
int a1[1000];
for(i=0;i<t;i++)
{
scanf("%d %d",&a,&b);
for(j=a;j<=b;j++)
{x=j;
n=j/1000>0?4:(n=j/100>0?3:(n=j/10>0?2:1));
if(j>=10)
{//printf("%d %d\n",j,n);
y=y+compute(j,n-1);
}
else
y=0;
k=0;
}
a1[i]=y;
y=0;
}
for(i=0;i<t;i++)
printf("Case #%d: %d\n",(i+1),a1[i]);
return 0;
}