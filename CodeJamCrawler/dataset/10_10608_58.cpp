#include<stdio.h>



int main()
{

int i,j,k,T,L,P,C,a[1000][2];
int t1,t2;
int ans;
float d;//a[0]=1;
//a[1]=1;
//al=1;

scanf("%d",&T);

for(i=0;i<T;i++)
{
 scanf("%d %d %d",&L,&P,&C);
 t1=P/L+!!(P%L);
 t2=C;
 ans=0;
 
 while(t1>t2)
 {
            // printf("%d %d\n",t1,t2);
            t2=t2*t2;
            ans++;
 }
 
 
  
 printf("Case #%d: %d\n",i+1,ans);               
 
}
    
 return 0;   
 }
