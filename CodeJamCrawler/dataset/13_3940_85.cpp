#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T,n,m,k,flag,full,i,j;
    int a[110][110];
    scanf("%d",&T);
    int cas=0;
    while (T--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
          for(j=0;j<m;j++){
            scanf("%d",&a[i][j]); 
          }
        flag=1;
        if(m>1&&n>1){
         for(i=0;i<n;i++){
          for(j=0;j<m;j++){
            if(a[i][j]==1){
              for(k=0;k<n;k++){
                if(a[k][j]!=1){ flag=0;  break; }                 
              } 
              if(!flag){
                for(k=0;k<m;k++){
                  if(a[i][k]!=1){ flag=-1;  break; }                 
                } 
                if(flag==-1)  flag=0;
                else          flag=1;         
              }
              if(flag==0)  break;              
            }               
          }
          if(flag==0)   break;              
         } 
        }
        if(flag==1) printf("Case #%d: YES\n",++cas);
        else        printf("Case #%d: NO\n",++cas);
    }
  //system("pause");
  return 0;
}
