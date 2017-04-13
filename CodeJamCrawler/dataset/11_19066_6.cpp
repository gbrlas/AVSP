#include<stdio.h>
#include<conio.h>
int main()
{
    int t, n, pd, pg, d, g, i, j, k, lost, flag;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
         scanf("%d",&n);
         scanf("%d",&pd);
         scanf("%d",&pg);
         for(j=1;j<=n;j++)
         {
               flag = 0;
               d = (int)(j*pd/100);
               if(d*100 == j*pd)
               {
                          lost = j - d;
                          for(k=0;;k++)
                          {
                                      if((pg==100)&&(pd==100))
                                      {
                                                flag = 1;
                                                break;
                                      }
                                      if((pg==0)&&(pd>0))
                                                break;
                                      if((pg>0)&&(pd==0))
                                                break;
                                      if((pg==0)&&(pd==0))
                                      {
                                                flag = 1;
                                                break;
                                      }
                                      if(((100-pg)==0)&&(lost>0))
                                              break;
                                      g = lost*100/(100-pg);
                                      if((g*(100-pg) == lost*100)&&(g-lost > d))
                                      {
                                                flag = 1;
                                                break;
                                      }
                                      lost++;
                          }
               }
               if(flag == 1)
               {
                       printf("Case #%d: Possible\n",i+1);
                       break;
               }
         }
         if(flag == 0)
         printf("Case #%d: Broken\n",i+1);
    }
    return 0;
}
         
                           
