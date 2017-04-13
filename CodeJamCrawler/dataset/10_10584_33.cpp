#include<stdio.h>


int main()
{
int a[32];
int i,j,T,N;
long K,b;

a[0]=1;
for(i=1;i<32;i++)
{
  a[i]=a[i-1]*2;               
}


scanf("%d",&T);

for(i=0;i<T;i++)
{
 scanf("%d %d",&N,&K);
 b=a[N]-1;
 printf("Case #%d: ",i+1);               

 if((K&b)==b)
     printf("ON\n");
 else
     printf("OFF\n");          
}
    
 return 0;   
    }
