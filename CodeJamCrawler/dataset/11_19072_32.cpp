#include<stdio.h>
#include<conio.h>
int main()
{
    int t, r, c, i, j, k, flag1, flag2;
    char tile[100][100];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
          scanf("%d %d",&r,&c);
          for(j=0;j<r;j++)
                 scanf("%s",tile[j]);
          printf("Case #%d:\n",i+1);
          for(j=0;j<r-1;j++)
          {
                 for(k=0;k<c-1;k++)
                 {
                         flag1 = 0;
                         if(tile[j][k]=='#')
                         {
                                if((tile[j+1][k]=='#')&&(tile[j][k+1]=='#')&&(tile[j+1][k+1]=='#'))
                                {
                                        tile[j][k] = '/' ;
                                        tile[j][k+1] = '\\' ;
                                        tile[j+1][k] = '\\' ;
                                        tile[j+1][k+1] = '/' ;
                                }
                                else
                                {
                                        flag1 = 1;
                                        break;
                                }
                         }
                 }
                 if(flag1)
                         break;
          }
          flag2 = 1;
          for(j=0;j<r;j++)
          {
                 for(k=0;k<c;k++)
                 {
                         if(tile[j][k]=='#')
                         {
                               flag2 = 0;
                               break;
                         }
                 }
                 if(flag2==0)
                          break;
          }
          if(flag2)
          {
                   for(j=0;j<r;j++)
                   {
                           for(k=0;k<c;k++)
                                 printf("%c",tile[j][k]);
                           printf("\n");
                   }
          }
          else
                   printf("Impossible\n");
    }
    return 0;
}
                 
