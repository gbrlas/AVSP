#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 10000000 
int judge(int m)
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
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T,a,b,k,flag,n,i,j;
    scanf("%d",&T);
    int cas=0,p[100];
    j=0;
    for(i=1;i<=100;i++){ 
          int tmp=i*i;
          if(judge(i)&&judge(tmp)){
            p[j++]=tmp;                        
          }
    }
    //for(i=0;i<j;i++) printf("%d ",p[i]); printf("\n");
    while (T--)
    {
        scanf("%d %d",&a,&b);
        n=0;
        for(i=0;p[i]<=b&&i<j;i++){
          if(p[i]>=a)   n++;               
        }
        printf("Case #%d: %d\n",++cas,n); 
    } 
  //system("pause");
  return 0;
}
