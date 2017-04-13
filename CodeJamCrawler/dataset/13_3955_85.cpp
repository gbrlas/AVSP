#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 10000000 
int judge(long long m)
{
  int a[110],i=0,j,len;
  while(m){
    a[i++]=m%10;
    m/=10;         
  }
  len=i;
  int flag=1;
  for(i=0,j=len-1;i<j;i++,j--){
    if(a[i]!=a[j]){  flag=0;  break; }                            
  } 
  return flag;   
}
int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);
    int T,cas=0;
    long long a,b,n,i,j;
    scanf("%d",&T);
    long long p[10000];
    j=0;
    for(i=1;i<=M;i++){ 
          long long tmp=i*i;
          if(judge(i)&&judge(tmp)){
            p[j++]=tmp;                        
          }
    }
    //for(i=0;i<j;i++) printf("%d ",p[i]); printf("\n");
    while (T--)
    {
        scanf("%lld %lld",&a,&b);
        n=0;
        for(i=0;p[i]<=b&&i<j;i++){
          if(p[i]>=a)   n++;               
        }
        printf("Case #%d: %lld\n",++cas,n); 
    } 
  //system("pause");
  return 0;
}
