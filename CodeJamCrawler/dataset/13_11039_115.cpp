#include <stdio.h>

int a[205][205];
int n1[205],m1[205];

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
       int n,m;
       scanf("%d%d",&n,&m);
       for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
       
       for(int i=0;i<n;i++)
       {
          n1[i]=0;
          for(int j=0;j<m;j++)
            if(a[i][j]>n1[i]) n1[i]=a[i][j];
       }
       
       for(int j=0;j<m;j++)
       {
          m1[j]=0;
          for(int i=0;i<n;i++)
            if(a[i][j]>m1[j]) m1[j]=a[i][j];
       }
       
       bool can=true;
       for(int i=0;i<n;i++)
       {
         for(int j=0;j<m;j++)
           if(a[i][j]<n1[i]&&a[i][j]<m1[j]){can=false;break;}
         if(!can) break;
       }
       
       printf("Case #%d: ",ca);
       if(can) printf("YES\n");
       else printf("NO\n");
    }
}
       
