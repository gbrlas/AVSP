#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
char plat[110][100];
int n,m;
int judge(int i,int j)
{
   if(i>=1&&i<=n&&j>=1&&j<=m)
      return 1;
    return 0;
}
int main()
{
  //  freopen("test.in","r",stdin);
   // freopen("test.out","w",stdout);
    int a,b,c,i,j,k,kk,k1,k2,tap=0;
    scanf("%d",&kk);
    for(int pp=1;pp<=kk;pp++)
    {
       tap=0;
       scanf("%d %d",&n,&m);
       getchar();
       for(i=1;i<=n;i++)
         {
           for(j=1;j<=m;j++)
             scanf("%c",&plat[i][j]);
            getchar();
         }
         for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
              if(plat[i][j]=='#')
              {
                  if(plat[i+1][j]=='#'&&plat[i][j+1]=='#'&&plat[i+1][j+1]=='#'&&judge(i+1,j)&&judge(i+1,j+1)&&judge(i,j+1))
                  {
                      plat[i][j]='/';
                      plat[i+1][j]=92;
                      plat[i][j+1]=92;
                      plat[i+1][j+1]='/';
                  }
              }
        for(i=1;i<=n;i++)
           for(j=1;j<=m;j++)
              if(plat[i][j]=='#')
                 tap=1;
        printf("Case #%d:\n",pp);
        if(tap==1)
          printf("Impossible\n");
        else
        for(i=1;i<=n;i++)
         {
           for(j=1;j<=m-1;j++)
             printf("%c",plat[i][j]);
            printf("%c\n",plat[i][j]);
         }

    }
}
