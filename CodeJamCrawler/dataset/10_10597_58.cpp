#include<stdio.h>



int main()
{
//long a[500];
//int al=0;
//long i,j,k,l,m,T,N,a1,a2,b1,b2;
//long ans;
//long K,b;
//c(5,2);
int i,j,k,T,N,a[1000][2];
int t1,t2;
int ans;
//a[0]=1;
//a[1]=1;
//al=1;

scanf("%d",&T);

for(i=0;i<T;i++)
{
 scanf("%d",&N);
 ans=0;
 //printf("N:%d",N);
 for(j=0;j<N;j++)
 {
 scanf("%d %d",&a[j][0],&a[j][1]);
 }

 for(j=1;j<N;j++)
 {
 for(k=0;k<N-j;k++)
    {
    if(a[k][0]>a[k+1][0])
        {
        t1=a[k][0];                 
        t2=a[k][1];
        a[k][0]=a[k+1][0];                 
        a[k][1]=a[k+1][1];
        a[k+1][0]=t1;
        a[k+1][1]=t2;
        }             
    }                
 }
 
 for(j=0;j<N;j++)
 {
 for(k=j+1;k<N;k++)
    {
    if(a[j][1]>a[k][1]) 
        ans++;            
                 
    }                
 }
  
 printf("Case #%d: %d\n",i+1,ans);               
 
}
    
 return 0;   
 }
