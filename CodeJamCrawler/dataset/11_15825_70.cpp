#include<stdio.h>


int main()
{
int i,j,k,n,N,c;
long a,r,s,e;

scanf("%d",&N);

for(n=1;n<=N;n++)
{
scanf("%d",&c);

scanf("%ld",&a);
r=a;
s=a;
c--;
while(c--)
{
scanf("%ld",&e);
a=(a>e?e:a);
r=r^e;
s=s+e;
}
printf("Case #%d: ",n);
if(r==0)
  printf("%ld",s-a);
else
	printf("NO");
printf("\n");

}


return 0;
}
