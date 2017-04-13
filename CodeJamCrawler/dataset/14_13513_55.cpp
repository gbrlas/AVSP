#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
main()
{
      int tc,k=1;
      scanf("%d",&tc);
      while(tc--)
      {
          int n;
          scanf("%d",&n);
          double naomi[n],ken[n];
          for(int i=0;i<n;i++)
          scanf("%lf",&naomi[i]);
          for(int i=0;i<n;i++)
          scanf("%lf",&ken[i]);
          sort(naomi,naomi+n);
          sort(ken,ken+n);
          int na=0,ke=0;
          int flag1,flag,vk[n],vn[n],index;
          for(int i=0;i<n;i++)
          vk[i]=vn[i]=0;
          for(int i=n-1;i>=0;i--)
          {
             flag=0,flag1=0;
             vn[i]=1;
             for(int j=0;j<n;j++)
             {
                 if(vk[j]==0 && flag1==0)
                 {
                    flag1=1;
                    index = j;
                 }
                 if(ken[j]>naomi[i] && vk[j]==0)
                 {
                    flag=1;
                    vk[j]=1;
                    break;
                 }
             }
             if(flag==1)
             {
                ke++;
             }
             else
             {
                 na++;
                 vk[index]=1;
             }
          }
          for(int i = 0;i<n;i++)
          vk[i]=vn[i]=0;
          int na1=0,ke1=0;
          int index1=0,index2=0 ,indext=n-1,round=0;
          for(int i=0;i<n;i++)
          {
             vn[i]=1;
             flag=0;
             for(int j=0;j<n;j++)
             {
                 if(vk[j]==0)
                 {
                     flag=1;
                     if(naomi[i]<ken[j])
                     {
                         for(int p=n-1;p>=0;p--)
                         {
                                 if(vk[p]==0)
                                 {
                                    ke1++;
                                    vk[p]=1;
                                    break;
                                 }
                         }
                     }
                     else
                     {
                        int p=j,prev=j;
                        while(p<n && naomi[i]>ken[p])
                        {
                           if(vk[p]==0)
                           prev=p;
                           p++;
                        }
                        na1++;
                        vk[prev]=1;
                     }
                 }
                 if(flag==1)
                 break;
             }
          }
          printf("Case #%d: %d %d \n",k,na1,na);
          k++;
      }
      return 0;
}
